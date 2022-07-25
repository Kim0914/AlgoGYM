#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
void make_list(int n, vector<vector<int>>& wires, vector<vector<int>>& wire_list){
    for(int i = 0; i < wires.size(); i++){
        if(i == n) continue;
        wire_list[wires[i][0]].push_back(wires[i][1]);
        wire_list[wires[i][1]].push_back(wires[i][0]);
    }
}
int search(int n, vector<vector<int>>& wire_list){
    queue<int> q;
    int cnt = 1;
    vector<bool> visit(wire_list.size(), false);
    q.push(n);
    visit[n] = true;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(int i = 0; i < wire_list[temp].size(); i++){
            if(!visit[wire_list[temp][i]]){
                visit[wire_list[temp][i]] = true;
                cnt++;
                q.push(wire_list[temp][i]);
            }
        }
    }
    return cnt;
}
int solution(int n, vector<vector<int>> wires) {
    int answer = 101;
    for(int i = 0; i < wires.size(); i++){
        vector<vector<int>> wire_list(n + 1);
        make_list(i, wires, wire_list);
        int first = search(1, wire_list), second = 0;
        for(int j = 2; j < wire_list.size(); j++){
            int temp = search(j, wire_list);
            if(first != temp){
                second = temp;
                break;
            }
        }
        if(second == 0) return 0;
        else{
            if(second > first){
                if(answer > second - first) answer = second - first;
            }
            if(first > second){
                if(answer > first - second) answer = first - second;
            }
        }
    }
    return answer;
}
