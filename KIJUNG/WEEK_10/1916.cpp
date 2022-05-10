#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define INF 2000000000

using namespace std;

int N, M, S, E, m[1001], edge[1001][1001];
priority_queue<pair<int,int>, vector<pair<int,int> >,  greater<pair<int,int> > > pq;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    FOR(i,1,N+1){
        FOR(j,1,N+1){
            edge[i][j] = INF;
        }
    }
    
    FOR(i,0,M){
        int a,b,c;
        cin >> a >> b >> c;
        if(edge[a][b] > c)
        edge[a][b] = c;
    }
    cin >> S >> E;

    FOR(i,1,N+1){
        m[i] = INF;
    }

    m[S] = 0;
    pq.push(make_pair(0,S));

    while(!pq.empty()){
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        FOR(i,1,N+1){
            if(edge[cur][i] != INF){
                int nCost = edge[cur][i];
                int next = i;

                if(m[next] > cost + nCost){
                    m[next] = cost + nCost;
                    pq.push(make_pair(m[next], next));
                }
            }
        }
    }

    cout << m[E];

    return 0;
}