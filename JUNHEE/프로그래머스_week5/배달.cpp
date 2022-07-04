#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<vector<pair<int,int>>> map(50);
bool visit[50] = {false, };
set <int> ans;
void backtrack(int cost, int limit, int start){
    if(cost > limit){
        return;
    }
    ans.insert(start);
    for(int i = 0; i < map[start].size(); i++){
        if(visit[map[start][i].first] == false){
            visit[map[start][i].first] = true;
            backtrack(cost + map[start][i].second, limit, map[start][i].first);
            visit[map[start][i].first] = false;
        }
    }
}
int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    int start, dest, cost;
    for(int i=0;i < road.size();i++){
        start = road[i][0] - 1; dest = road[i][1] - 1; cost = road[i][2];
        map[start].push_back(make_pair(dest, cost));
        map[dest].push_back(make_pair(start, cost));
    }  
    visit[0] = true;
    backtrack(0,K,0);

    return ans.size();
}
