#include <iostream>
#include <vector>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N, E, cnt, t1, t2, visited[101], edge[101][101];
vector<int> v;

void dfs(){
    cnt ++;
    int start = v.back();
    v.pop_back();
    visited[start] = 1;

    FOR(i,1,N+1){
        if(edge[start][i] == 1){
            if(visited[i] == 0) {
                v.push_back(i);
                dfs();
            }
        }
    }
}

int main(void){
    cin >> N >> E;
    FOR(i,0,E){
        cin >> t1 >> t2;
        edge[t1][t2] = 1;
        edge[t2][t1] = 1;
    }

    v.push_back(1);
    dfs();

    cout << cnt-1;
    return 0;
}