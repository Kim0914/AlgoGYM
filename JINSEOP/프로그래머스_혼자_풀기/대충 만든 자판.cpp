#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<char, int> key_hash;
void make_keyhash(vector<string> keymap) {
    for (string s : keymap) {
        for (int i = 0; i < s.size(); i++) {
            if (key_hash[s[i]] == 0)
                key_hash[s[i]] = i + 1;
            else if(key_hash[s[i]] > i + 1)
                key_hash[s[i]] = i + 1;
        }
    }
}

vector<int> make_target(vector<string> targets) {
    vector<int> answer;

    for (string s : targets) {
        int cnt = 0;

        for (char c : s) {
            if (key_hash[c] == 0) {
                cnt = 0;
                break;
            }
            cnt += key_hash[c];
        }

        if (cnt == 0)
            answer.push_back(-1);
        else
            answer.push_back(cnt);
    }

    return answer;
}

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;

    make_keyhash(keymap);
    answer = make_target(targets);
    return answer;
}
