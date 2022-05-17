#include <iostream>
#include <vector>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int V, E, visited[10001];
vector<pair<int,int> > edge[10001];
int M = 2147483647;

void dfs(int cur, int cnt, int weight){
    if(cnt == V-1) M = min(M, weight);
    if(cnt > V-1) return;

    FOR(i,0,edge[cur].size()){
        int next = edge[cur][i].first;
        if(visited[next] == 1) continue;
        visited[next] = 1;
        dfs(next, cnt+1, weight+edge[cur][i].second);
        visited[next] = 0;
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> V >> E;

    FOR(i,0,E){
        int a,b,c;
        cin >> a >> b >> c;
        edge[a].push_back(make_pair(b,c));
        edge[b].push_back(make_pair(a,c));
    }

    visited[1] = 1;
    dfs(1,0,0);

    cout << M;

    return 0;
}

//무지성 풀이.. 시간초과임.