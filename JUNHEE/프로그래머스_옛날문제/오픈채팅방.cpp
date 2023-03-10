#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

struct rcd{
    string status;
    string id;
};

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> ids;
    vector<rcd> records;
    stringstream ss;
    for(int i = 0; i < record.size();i++){
        ss.str(record[i]);
        string t_status, t_id, t_name;
        ss >> t_status >> t_id >> t_name;
        if(t_status == "Change"){
            ids[t_id] = t_name;
        }
        else if(t_status == "Enter") {
            struct rcd t_rcd = {t_status, t_id};
            ids[t_id] = t_name;
            records.push_back(t_rcd);
        }
        else {
            struct rcd t_rcd = {t_status, t_id};
            records.push_back(t_rcd);
        }
        ss.clear();
    }
    for(auto k : records){
        if(k.status == "Enter"){
            string t_answer = ids[k.id] + "님이 들어왔습니다.";
            answer.push_back(t_answer);
        }
        else{
            string t_answer = ids[k.id] + "님이 나갔습니다.";
            answer.push_back(t_answer);
        }
    }
    return answer;
}
