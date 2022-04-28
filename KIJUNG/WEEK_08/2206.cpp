#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N, M, pX, pY, comp;
int map[1003][1003] = {1,};
int compVisited[1001][1001];
int compMap[1003][1003];
int m = 2000000000;
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};

vector<pair<int,int> > v;
queue<pair<int,int> > q;

string str;

void dfs(int y, int x){
    compVisited[y][x] = 1;
    compMap[y][x] = comp;

    FOR(i,0,4){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny<1 || nx<1 || ny>N || nx>M) continue;
        if(map[ny][nx] == 0 && compVisited[ny][nx] == 0){
            dfs(ny,nx);
        }
    }
}

int main(void){
    cin >> N >> M;

    FOR(i,1,N+1){
        cin >> str;
        FOR(j,0,M){
            map[i][j+1] = str[j]-48;
        }
    }

    // 1. 컴포넌트 구하고 번호매기기
    FOR(i,1,N+1){
        FOR(j,1,M+1){
            if(map[i][j] == 0 && compVisited[i][j] == 0){
                comp++;
                dfs(i,j);
            }
        }
    }
    
    // 어느 무리에 속해 있는가?
    int iComp = compMap[1][1];
    int aComp = compMap[N][M];

    // 2. 후보군 구하기
    // 부술 수 있는 벽이 없는 경우
    v.push_back(make_pair(1,1));
    // 부술 벽이 있는 경우
    FOR(i,1,N+1){
        FOR(j,1,M+1){
            if(map[i][j] == 1){
                if((compMap[i][j-1] == iComp && compMap[i][j+1] == aComp) ||
                    (compMap[i][j-1] == aComp && compMap[i][j+1] == iComp)){
                        v.push_back(make_pair(i,j));
                    }
                if((compMap[i-1][j] == iComp && compMap[i+1][j] == aComp) ||
                    (compMap[i-1][j] == aComp && compMap[i+1][j] == iComp)){
                    v.push_back(make_pair(i,j));
                } 
            }
        }
    }

    // FOR(i,0,v.size()){
    //     cout << v[i].first << " " << v[i].second << "\n";
    // }

    // 3. 후보군마다 부쉈을 때를 가정해서 bfs로 최단거리를 구한다.
    FOR(i,0,v.size()){
        int visited[1001][1001] = {0,};
        int pY = v[i].first;
        int pX = v[i].second;

        map[pY][pX] = 0;

        q.push(make_pair(1,1));
        visited[1][1] = 1;
        while(!q.empty()){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            FOR(l,0,4){
                int ny = y+dy[l];
                int nx = x+dx[l];

                if(ny<1 || nx<1 || ny>N || nx>M) continue;
                if(map[ny][nx] == 0 && visited[ny][nx] == 0){
                    q.push(make_pair(ny,nx));
                    visited[ny][nx] = visited[y][x]+1;
                }
            }
        }

        map[pY][pX] = 1;

        // 4. 최솟값 구하기
        if(visited[N][M]>0) {
            // cout << "p[" << pY << "," << pX << "] : " << visited[N][M] << "\n"; 
            m = min(visited[N][M],m);
        }
    }

    if(m == 2000000000) m = -1;
    cout << m;

    return 0;
}

// 씨발

// <풀이 방법>
// 1. dfs로 컴포넌트를 구한다.
// 2. 컴포넌트 나눠서 1,1 컴포넌트랑  N,M 컴포넌트를 사이에 둔 벽을 후보군으로 넣는다.
// 2. 후보군(해당 후보군 벽을 하나 부쉈을 때) 마다 bfs를 돌림.
// 3. 그 중 최솟값을 출력.

// 이래도 시간초과 걸리네..
// 답보고 내일 다시 도전!