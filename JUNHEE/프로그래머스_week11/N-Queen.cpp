#include <string>
#include <vector>
#include <iostream>

using namespace std;
int answer = 0;
bool check(vector<pair<int,int>>& q_pos, int x, int y){
    for(int i = 0; i < q_pos.size(); i++){
        int t_x = q_pos[i].first;
        int t_y = q_pos[i].second;
        if(x == t_x) return false;
        if(y == t_y) return false;
        int cal_x = abs(x - t_x);
        int cal_y = abs(y - t_y);
        if(cal_x == cal_y) return false;
    }
    return true;
}
void n_queen(int n, int cnt, vector<pair<int,int>> q_pos, int pre_x){
    if(n == cnt){
        answer++;
        return;
    }
    for(int j = 0; j < n; j++){
        if(check(q_pos, pre_x + 1, j)){
            q_pos.push_back(make_pair(pre_x + 1,j));
            n_queen(n, cnt + 1, q_pos, pre_x + 1);
            q_pos.pop_back();
        }
    }
}
int solution(int n) {
    vector<pair<int,int>> q_pos;
    n_queen(n,0,q_pos,-1);
    return answer;
}
