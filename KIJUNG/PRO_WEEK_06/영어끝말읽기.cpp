#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer{0,0};
    map<string, int> m;
    
    char last = words[0][words[0].size()-1];
    m[words[0]] = 1;
    
    for(int i=1;i<words.size();i++){
        if(last != words[i][0] || m[words[i]] == 1) {
            answer[0] = i%n+1;
            answer[1] = i/n+1;
            break;
        }
        m[words[i]] = 1;
        last = words[i][words[i].size()-1];
    }

    return answer;
}