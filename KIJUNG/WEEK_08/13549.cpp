#include <iostream>
#include <queue>

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define INF 2000000000

using namespace std;

int N, K, m[100002];
priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;

void valid(int cur, int cost, int next, int plus){
    if(next<0 || next>100000) return;
    if(m[next] > cost+plus){
        m[next] = cost+plus;
        pq.push(make_pair(cost+plus, next));
    }
}

int main(void){
    cin >> N >> K;

    fill_n(m,100002,INF);
    pq.push(make_pair(0,N));
    
    while(!pq.empty()){
        int cost = pq.top().first;
        int cur = pq.top().second;
        // cout << cost << " " << cur << "\n";
        pq.pop();
        if(cur == K) break;

        valid(cur,cost,cur*2,0);
        valid(cur,cost,cur+1,1);
        valid(cur,cost,cur-1,1);
    }
    cout << m[K];

    return 0;
}