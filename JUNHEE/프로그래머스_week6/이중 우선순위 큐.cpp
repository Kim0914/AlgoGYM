#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2);
    priority_queue<int, vector<int>, greater<int>> pq_asc;
    priority_queue<int, vector<int>> pq_des;
    int cnt = 0;
    
    for(string op : operations) {
        if(!cnt) {
            while(!pq_asc.empty()) pq_asc.pop();
            while(!pq_des.empty()) pq_des.pop();
        }
        if(op[0] == 'I') {
            pq_des.push(stoi(op.substr(2)));
            pq_asc.push(stoi(op.substr(2)));
            cnt++;
        }
        else {
            if(cnt == 0) continue;
            if(op[2] == '1') {
                pq_des.pop();
                cnt--;
            }
            else {
                pq_asc.pop();
                cnt--;
            }
        }
    }
    
    if(cnt) {
        answer[0] = pq_des.top();
        answer[1] = pq_asc.top();
    }
    
    return answer;
}
