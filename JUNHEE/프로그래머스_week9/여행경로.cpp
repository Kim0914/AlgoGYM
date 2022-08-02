#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;
bool flag = false;
void DFS(string now, vector<vector<string>>& tickets, vector<bool>& visit, int size){
    answer.push_back(now);
    if(size == tickets.size()){
        flag = true;
        return;
    }
    for(int i = 0; i < tickets.size(); i++){
        if(visit[i] == false && tickets[i][0] == now){
            visit[i] = true;
            DFS(tickets[i][1], tickets, visit, size + 1);
            if(flag) return;
            visit[i] = false;
            answer.pop_back();
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    
    vector<bool> visit(tickets.size(), false);
    sort(tickets.begin(), tickets.end());
    DFS("ICN",tickets,visit,0);
    return answer;
}
