#include <iostream>
#include <queue>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N, K, visited[100002];
queue<int> q;

void valid(int cur, int next){
    if(next<0 || next>100000) return;
    if(visited[next] >= 1) return;

    visited[next] = visited[cur]+1;
    q.push(next);
}

int main(void){
    cin >> N >> K;

    q.push(N);
    visited[N] = 1;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        valid(cur,cur+1);
        valid(cur,cur-1);
        valid(cur,cur*2);
    }
    cout << visited[K]-1;

    return 0;
}