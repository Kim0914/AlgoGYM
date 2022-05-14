#include <iostream>
#include <vector>
#include <algorithm>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int n, m, tree;
vector<int> edge[501];
int visited[501];

bool dfs(int cur){
    if(visited[cur]) return false;
    visited[cur] = true;
    FOR(i,0,edge[cur].size()){
        if(!dfs(edge[cur][i])) return false;
    }
    return true;
}

int main(void){
    while(1){
        cin >> n >> m;
        if(n==0 && m ==0) break;
        FOR(i,0,m){
            int tmp1, tmp2;
            cin >> tmp1 >> tmp2;
            edge[tmp1].push_back(tmp2);
            edge[tmp2].push_back(tmp1);
        }
        FOR(i,1,n+1){
            cout<<i<< " " <<dfs(i) <<"\n";
            // if(dfs(i)) tree++;
        }
    }
    cout << tree;



    return 0;
}