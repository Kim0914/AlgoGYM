#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

unordered_set<string> validator;
pair<int, int> ans;
void word_relay(int n, vector<string> words) {
    int person_cnt = 2, cnt = 1;
    validator.insert(words[0]);

    for (int i = 1; i < words.size(); i++) {
        if (i % n == 0) cnt++;
        int v_size = validator.size();
        validator.insert(words[i]);

        if (words[i - 1][words[i - 1].size() - 1] != words[i][0]) {
            ans.first = person_cnt;
            ans.second = cnt;
            return;
        }
        
        if (v_size == validator.size()) {
            ans.first = person_cnt;
            ans.second = cnt;
            return;
        }
        
        person_cnt++;
        if (person_cnt > n) person_cnt = 1;
    }
    
    person_cnt = 0; cnt = 0;
}

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;

    word_relay(n, words);
    answer.push_back(ans.first);
    answer.push_back(ans.second);

    return answer;
}
