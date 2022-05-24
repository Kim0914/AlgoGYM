#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define INF 2000000000

using namespace std;

int N, K, m[100002], before[100002];
stack<int> s;
priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;

void valid(int cur, int cost, int next, int plus){
    if(next<0 || next>100000) return;
    if(m[next] > cost+plus){
        m[next] = cost+plus;
        before[next] = cur;
        pq.push(make_pair(cost+plus, next));
    }
}

int main(void){
    cin >> N >> K;

    fill(m,m+100002,INF);
    pq.push(make_pair(0,N));
    
    while(!pq.empty()){
        int cost = pq.top().first;
        int cur = pq.top().second;
        // cout << cost << " " << cur << "\n";
        pq.pop();
        if(cur == K) {
            m[K] = cost;
            break;
        }
        valid(cur,cost,cur*2,1);
        valid(cur,cost,cur+1,1);
        valid(cur,cost,cur-1,1);
    }
    cout << m[K] << "\n";

    s.push(K);
    while(s.top() != N){
        s.push(before[s.top()]);
    }

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}