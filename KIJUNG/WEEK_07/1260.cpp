#include <iostream>
#include <deque>
#include <algorithm>


#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int edge[1001][1001];
int visited[1001];
int N, M, V, t1,t2;
deque<int> d;

void dfs(){
    int start = d.back();
    d.pop_back();
    if(visited[start] == 1) return;
    cout << start << " ";

    visited[start] = 1;

    FOR(i,1,N+1){
        if(edge[start][i] == 1){
            d.push_back(i);
            dfs();
        }
    }
}

void bfs(){
    while (!d.empty()){
        int start = d.front();
        d.pop_front();
        
        cout << start << " ";

        FOR(i,1,N+1){
            if(edge[start][i] == 1){
                if(visited[i] != 1) {
                    d.push_back(i);
                    visited[i] = 1;
                }
            }
        }
    }
}

int main(void){
    cin >> N >> M >> V;
    FOR(i,0,M){
        cin >> t1 >> t2;
        edge[t1][t2] = 1;
        edge[t2][t1] = 1;
    }
    d.push_back(V);
    dfs();

    d.clear();
    fill_n(visited, 1001, 0);

    cout << "\n";

    visited[V] = 1;
    d.push_back(V);
    bfs();

    return 0;
}

// 1 4 2 5