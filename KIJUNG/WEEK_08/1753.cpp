#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define INF 2000000000
#define FOR(i,a,b) for(int i =a;i<b;i++)

using namespace std;

int V, E, sNode, u, v, w;
vector<pair<int,int> > edge[20001];
int d[20001];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E >> sNode;

    FOR(i,0,E){
        cin >> u >> v >> w;
        edge[u].push_back(make_pair(v,w));
    }

    fill_n(d+1,V,INF);
    d[sNode] = 0;

    pq.push(make_pair(0,sNode));

    while(!pq.empty()){

        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        FOR(i,0,edge[cur].size()){
            int next = edge[cur][i].first;
            int nCost = edge[cur][i].second;
            if(d[next] > cost + nCost){
                d[next] = cost + nCost;
                pq.push(make_pair(d[next], next));
            }
        }
    }

    FOR(i,1,V+1){
        if(d[i] == INF) cout << "INF\n";
        else cout << d[i] << "\n";
    }
    
    return 0;
}