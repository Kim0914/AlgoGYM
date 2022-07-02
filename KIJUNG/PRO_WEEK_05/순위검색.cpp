#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    vector<vector<string> > splitInfos;
    for(string i: info){
        stringstream ss(i);
        string tmp;
        vector<string> splitInfo;
        while(ss>>tmp){
            splitInfo.push_back(tmp);
        }
        splitInfos.push_back(splitInfo);
    }
    
    vector<vector<string> > splitQuerys;
    for(string q: query){
        stringstream ss(q);
        string cond;
        vector<string> splitQuery;
        while(ss>>cond){
            if(cond == "and") continue;
            splitQuery.push_back(cond);
        }
        splitQuerys.push_back(splitQuery);
    }
    
    for(vector<string> splitQuery: splitQuerys){
        int cnt = 0;
        for(vector<string> splitInfo: splitInfos){
            bool f = true;
            for(int i=0;i<4;i++){
                if(splitQuery[i] == "-") continue;
                if(splitQuery[i] != splitInfo[i]) {
                    f = false;
                    break;
                }
            }
            if(f && stoi(splitQuery[4]) > stoi(splitInfo[4])) f = false;
            if(f) cnt++;
        }
        answer.push_back(cnt);
    }
    
    return answer;
}