#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int V;
vector<pair<int,int> > edge[100001];
bool visited[100001];
int max_point;
int M = 0;

void dfs(int cur, int cnt){
    if(visited[cur]) return;
    if(M < cnt){
        M = cnt;
        max_point = cur;
    }
    visited[cur] = true;
    FOR(i,0,edge[cur].size()){
        dfs(edge[cur][i].first, cnt+edge[cur][i].second);
    }
}

int main(void){
    cin >> V;
    FOR(i,1,V+1){
        int tmp3;
        cin >> tmp3;
        while(1){
            int tmp1, tmp2;
            cin >> tmp1;
            if(tmp1 == -1) break;
            cin >> tmp2;
            edge[tmp3].push_back(make_pair(tmp1, tmp2));
        }
    }

    dfs(1,0);
    M = 0;
    fill(visited, visited+100001, false);
    dfs(max_point,0);

    cout << M;

    return 0;
}