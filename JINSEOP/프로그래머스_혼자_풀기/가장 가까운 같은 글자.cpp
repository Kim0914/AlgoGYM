#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<char, int> cache;
vector<int> solution(string s) {
    vector<int> answer;
    
    for (int i = 0; i < s.size(); i++) {
        if (!cache[s[i]]) {
            answer.push_back(-1);
            cache[s[i]] = i + 1;
        }
        else {
            answer.push_back((i + 1) - cache[s[i]]);
            cache[s[i]] = i + 1;
        }
    }

    return answer;
}
