#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <math.h>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N, M, m, map[11][11], parent[7];
int visited[11][11];
int comp = 1;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
vector<array<int,3> > edge;

void addEdge(int y, int x){
    FOR(i,0,4){
        int curY = y;
        int curX = x;
        while(1){
            curY += dy[i];
            curX += dx[i];
            if(curY<1 || curY>N || curX<1 || curX>M) break;
            int len = max(abs(curY-y),abs(curX-x));
            if(map[curY][curX] == 1){
                if(visited[curY][curX] != visited[y][x]){
                    if(len>2){
                        array<int,3> arr;
                        arr[0] = len-1;
                        arr[1] = visited[y][x];
                        arr[2] = visited[curY][curX];
                        edge.push_back(arr);
                        break;
                    }
                    else break;
                }
                else break;
            }
        }
    }
}

int findRoot(int v){
    if(parent[v] == v) return v;
    else return parent[v] = findRoot(parent[v]);
}

void unionRoot(int v1, int v2){
    parent[findRoot(v1)] = findRoot(v2);
}

void possible(){
    FOR(i,1,comp){
        if(findRoot(1) != findRoot(i)) m = -1;
    }
}

void dfs(int y, int x){
    if(y<1 || y>N || x<1 || x>M) return;
    if(visited[y][x] != 0 || map[y][x] != 1) return;

    visited[y][x] = comp;
    FOR(i,0,4){
        dfs(y+dy[i], x+dx[i]);
    }
}

int main(void){
    cin >> N >> M;
    FOR(i,1,N+1){
        FOR(j,1,M+1){
            cin >> map[i][j];
        }
    }

    
    FOR(i,1,N+1){
        FOR(j,1,M+1){
            if(visited[i][j] == 0 && map[i][j] == 1){
                dfs(i,j);
                comp++;
            }
        }
    }

    FOR(i,1,comp) parent[i] = i;
    
    FOR(i,1,N+1){
        FOR(j,1,M+1){
            if(map[i][j] == 1) addEdge(i,j);
        }
    }

    sort(edge.begin(), edge.end());

    FOR(i,0,edge.size()){
        if(findRoot(edge[i][1]) != findRoot(edge[i][2])){
            unionRoot(edge[i][1], edge[i][2]);
            m += edge[i][0];
        }
    }

    possible();
    cout << m;

    return 0;
}