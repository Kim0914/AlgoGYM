#include <iostream>
#include <algorithm>
#include <queue>

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define INF 100000000

using namespace std;

int n, m, a, b, c, dis[101];
int edge[101][101] = {INF, };
priority_queue<pair<int,int> , vector<pair<int,int> >, greater<pair<int,int> > > pq;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    
    FOR(i,1,n+1){
        FOR(j,1,n+1){
            edge[i][j] = INF;
        }
    }

    FOR(i,0,m){
        cin >> a >> b >> c;
        if(edge[a][b] > c)
        edge[a][b] = c;
    }

    FOR(l,1,n+1){

        FOR(i,1,n+1){
            dis[i] = INF;
        }
        dis[l] = 0;
        pq.push(make_pair(0,l));

        while(!pq.empty()){
            int cost = pq.top().first;
            int cur = pq.top().second;
            pq.pop();

            FOR(i,1,n+1){
                if(edge[cur][i] != INF){
                    int next = i;
                    int nCost = edge[cur][i];

                    if(dis[next] > cost + nCost){
                        dis[next] = cost + nCost;
                        pq.push(make_pair(dis[next], next));
                    }
                }
            }
        }
        FOR(i,1,n+1){   
            if(dis[i] == INF) cout << 0 << " ";
            else cout << dis[i] << " ";
        }
        
        cout << "\n";

    }

    return 0;
}

//다익스트라 알고리즘