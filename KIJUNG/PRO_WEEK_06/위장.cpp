#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string,int> m;
    
    for(vector<string> cloth: clothes) m[cloth[1]]++;
    for(pair<string,int> p: m) answer *= p.second+1;
    
    return answer-1;
}