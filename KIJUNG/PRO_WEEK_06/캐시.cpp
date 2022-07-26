#include <string>
#include <vector>
#include <deque>

using namespace std;

deque<pair<int, string>> d;

int solution(int cacheSize, vector<string> cities) {
    int cnt = 0;
    int answer = 0;
    
    if(cacheSize==0) return cities.size()*5;
    
    for(string city: cities){
        int sameIdx = 31;
        int minIdx = 31;
        int minCnt = 2000000000;
        string tmp = "";
        
        for(char c:city) tmp += tolower(c);
        city = tmp;
    
        for(int i=0;i<d.size();i++){
            if(d[i].second == city) sameIdx = i;
            if(minCnt>d[i].first){
                minCnt = d[i].first;
                minIdx = i;
            }
        }
        
        if(sameIdx != 31) {
            d[sameIdx].first = cnt++;
            answer += 1;
        }
        else {
            if(d.size() < cacheSize) d.push_back(make_pair(cnt++, city));
            else d[minIdx] = make_pair(cnt++, city);                
            answer += 5;
        }
        
    }
    return answer;
}