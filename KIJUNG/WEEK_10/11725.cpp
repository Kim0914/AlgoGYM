#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N;
vector<int> edge[100001];
int parent[100001];
bool visited[100001];
queue<int> q;


int main(void){
    cin >> N;
    FOR(i,0,N-1){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        edge[tmp1].push_back(tmp2);
        edge[tmp2].push_back(tmp1);
    }

    q.push(1);
    visited[1] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        FOR(i,0,edge[cur].size()){
            if(visited[edge[cur][i]]) continue;
            visited[edge[cur][i]] = true;
            parent[edge[cur][i]] = cur;
            q.push(edge[cur][i]);
        }
    }

    FOR(i,2,N+1){
        cout << parent[i] << "\n";
    }
    
    return 0;
}