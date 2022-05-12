#include <iostream>
#include <vector>
#include <algorithm>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N, max_idx, M;
bool visited[10001];
vector<pair<int,int> > edge[10001];

void dfs(int cur, int distance){
    if(visited[cur]) return;
    if(M<distance){
        max_idx = cur;
        M = distance;
    }
    visited[cur] = true;
    FOR(i,0,edge[cur].size()){
        dfs(edge[cur][i].first, distance+edge[cur][i].second);
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    FOR(i,0,N-1){
        int a,b,c;
        cin >> a >> b >> c;
        edge[a].push_back(make_pair(b,c));
        edge[b].push_back(make_pair(a,c));
    }

    dfs(1,0);
    fill(visited, visited+10001, false);
    M=0;
    dfs(max_idx,0);
    cout << M;

    return 0;
}