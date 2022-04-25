#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int M, N, map[101][101], check[101][101];
bool visited[101][101];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
queue<pair<int,int> > q;
string str;

int main(void){

    cin >> N >> M;

    FOR(i,1,N+1){
        cin >> str;
        FOR(j,1,M+1){
            map[i][j] = str[j-1] - 48;
        }
    }

    q.push(make_pair(1,1));
    visited[1][1] = true;
    while(!q.empty()){
        pair<int,int> tmp = q.front();
        int y = tmp.first;
        int x = tmp.second;
        q.pop();

        FOR(i,0,4){
            int ny = y+dy[i];
            int nx = x+dx[i];

            if(ny < 1 || ny > N || nx < 1 || nx > M) continue;
            if(map[ny][nx] == 0 || visited[ny][nx] == true) continue;
            q.push(make_pair(ny, nx));
            visited[ny][nx] = true;
            check[ny][nx] = check[y][x]+1;
        }
    }

    cout << check[N][M]+1;

    return 0;
}

// 큐,스택,벡터 같은 자료형이 있다면 넣기전에 조건문으로 안되는 상황을 걸러주게끔 코드를 작성하는 것이 좋다.
// 왜냐하면 그렇게 하지 않으면 메모리 초과의 가능성이 생기기 때문.