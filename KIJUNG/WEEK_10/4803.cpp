#include <iostream>
#include <vector>
#include <algorithm>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int n, m;
int T = 1;
vector<int> edge[501];
bool visited[501];

bool dfs(int cur, int prev){
    if(visited[cur]) return false;
    visited[cur] = true;
    FOR(i,0,edge[cur].size()){
        if(edge[cur][i]==prev) continue;
        if(!dfs(edge[cur][i],cur)) return false;
    }
    return true;
}

int main(void){
    while(1){
        cin >> n >> m;
        if(n==0 && m ==0) break;
        int tree = 0;

        FOR(i,0,m){
            int tmp1, tmp2;
            cin >> tmp1 >> tmp2;
            edge[tmp1].push_back(tmp2);
            edge[tmp2].push_back(tmp1);
        }
        FOR(i,1,n+1){
            // cout<<i<< " " <<dfs(i,0) <<"\n";
            if(dfs(i,0)) tree++;
        }

        cout << "Case " << T++ << ": ";
        if(tree == 0) cout <<  "No trees.\n";
        else if(tree == 1) cout << "There is one tree.\n";
        else cout << "A forest of " << tree << " trees.\n";

        FOR(i,1,n+1){
            edge[i].clear();
            visited[i] = false;
        }
    }

    return 0;
}