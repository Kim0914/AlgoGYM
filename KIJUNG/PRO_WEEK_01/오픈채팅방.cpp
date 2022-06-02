#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

#define FOR(i,a,b) for(int i=a; i<b; i++)

using namespace std;

vector<string> logAct;
vector<string> logUserId;
map<string,string> mappingNickName;


vector<string> solution(vector<string> record) {
    
    FOR(i,0,record.size()){
        stringstream ss(record[i]);
        string tmpAct, tmpUserId, tmpNickName;
        
        ss >> tmpAct;
        ss >> tmpUserId;
        if(tmpAct != "Leave") ss >> tmpNickName;

        if(tmpAct != "Leave") mappingNickName[tmpUserId] = tmpNickName;
        if(tmpAct != "Change") {
            logAct.push_back(tmpAct);
            logUserId.push_back(tmpUserId);
        }
    }
    
    vector<string> answer;
                
    FOR(i,0,logAct.size()){
        string sentence = mappingNickName[logUserId[i]]+"님이 ";
        if(logAct[i] == "Enter") sentence +="들어왔습니다.";
        else sentence +="나갔습니다.";
        answer.push_back(sentence);
    }
    
    return answer;
}