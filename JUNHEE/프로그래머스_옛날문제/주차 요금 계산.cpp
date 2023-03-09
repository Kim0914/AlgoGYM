#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;
int time_to_int(string time){
    string hour = time.substr(0,2);
    string min = time.substr(3,2);
    int t = stoi(hour) * 60 + stoi(min);
    return t;
}
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, vector<string>> cost_map;
    stringstream ss;
    for(int i = 0; i < records.size(); i++) {
        ss.str(records[i]);
        string time, number, status;
        ss >> time >> number >> status;
        cost_map[number].push_back(time);
        ss.clear();
    }
    for(auto m : cost_map){
        int total_time = 0;
        if(m.second.size() % 2 == 1)
            m.second.push_back("23:59");
        for(int i = 0; i < m.second.size(); i += 2){
            total_time += time_to_int(m.second[i + 1]) - time_to_int(m.second[i]);
        }
        if(total_time < fees[0]) answer.push_back(fees[1]);
        else {
            int cost = fees[1];
            if((total_time - fees[0]) % fees[2] != 0)
                cost += ((total_time - fees[0]) / fees[2] + 1) * fees[3];
            else
                cost += ((total_time - fees[0]) / fees[2]) * fees[3];
            answer.push_back(cost);
        }
        
    }
    return answer;
}
