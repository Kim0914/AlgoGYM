#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> info;
    string answer = "";
    
    for(int comp = 0; comp<completion.size(); comp++) info[completion[comp]]++;
    for(int part = 0; part<participant.size(); part++) info[participant[part]]++;
    for(auto i : info){
        if(i.second % 2 == 1) answer = i.first;
    }
    
    return answer;
}
