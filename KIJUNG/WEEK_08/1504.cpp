#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define INF 100000000

using namespace std;

int N, E, a, b, c, v1, v2, ans, d[801], v[2];
vector<pair<int,int> > edge[801];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;

int ds(int start, int end){

    fill_n(d+1,N,INF);
    d[start] = 0;
    pq.push(make_pair(0,start));

    while(!pq.empty()){
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        

        FOR(i,0,edge[cur].size()){
            int next = edge[cur][i].first;
            int nCost = edge[cur][i].second;

            if(d[next] > cost + nCost){
                d[next] = cost + nCost;
                pq.push(make_pair(d[next],next));
            }
        }
    }
    return d[end];
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> E;
    FOR(i,0,E){
        cin >> a >> b >> c;
        edge[a].push_back(make_pair(b,c));
        edge[b].push_back(make_pair(a,c));
    }
    cin >> v[0] >> v[1];
    
    ans = min(ds(1,v[0]) + ds(v[0],v[1]) + ds(v[1],N), ds(1,v[1]) + ds(v[1],v[0]) + ds(v[0],N));
    if(ans >= INF) ans = -1;
    cout << ans;

}