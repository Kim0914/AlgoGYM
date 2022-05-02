#include <iostream>
#include <algorithm>
#include <queue>

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define INF 100000000

using namespace std;

int V, E, a, b, c, ans, dis[401];
vector<pair<int,int> > edge[401];
priority_queue<pair<int,int> , vector<pair<int,int> >, greater<pair<int,int> > > pq;

int ds(int start, int end){
    FOR(i,1,V+1){
        dis[i] = INF;
    }
    dis[start] = 0;
    pq.push(make_pair(0,start));

    while(!pq.empty()){
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        FOR(i,0,edge[cur].size()){
            int next = edge[cur][i].first;
            int nCost = edge[cur][i].second;

            if(dis[next] > cost + nCost){
                dis[next] = cost + nCost;
                pq.push(make_pair(dis[next], next));
            }
        }
    }
    
    return dis[end];
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;

    FOR(i,0,E){
        cin >> a >> b >> c;
        edge[a].push_back(make_pair(b,c));
    }

    // cout << "ds " << ds(1,V) <<" "<< ds(V,1) << "\n";
    ans=INF;
    FOR(i,1,V){
        FOR(j,i+1,V+1){
            int ans1 = ds(i,j);
            if(ans1 == INF) continue;
            int ans2 = ds(j,i);
            ans = min(ans1+ans2, ans);
        }
    }
    if(ans>=INF) cout << -1;
    else cout << ans;
    

    return 0;
}

// 다익스트라 알고리즘: 시간초과.
// 노드의 갯수가 작으므로 O(n^3)인 플로이드 워셜 알고리즘을 쓸 수 있다. 
// 1956_2.cpp 참고!