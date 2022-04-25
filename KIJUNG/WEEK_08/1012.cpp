#include <iostream>
#include <algorithm>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int T, M, N, K, baecu[51][51], visited[51][51], t1, t2, component;
// M: 가로길이, N: 세로길이

void sol(int y, int x){

    if(y < 0 || y >= N || x < 0 || x >= M) return;
    if(baecu[y][x] == 0) return;
    if(visited[y][x] == 1) return;

    visited[y][x] = 1;

    sol(y, x-1);
    sol(y-1, x);
    sol(y, x+1);
    sol(y+1, x);
}

int main(void){

    cin >> T;

    FOR(l,0,T){
        cin >> M >> N >> K;
        FOR(i,0,K){
            cin >> t1 >> t2;
            baecu[t2][t1] = 1;
        }

        FOR(i,0,N){
            FOR(j,0,M){
                if(baecu[i][j] == 1 && visited[i][j] == 0){

                    component++;
                    sol(i,j);
                }
            }
        }

        cout << component << "\n";

        //초기화
        component = 0;
        FOR(i,0,50){
            FOR(j,0,50){
                baecu[i][j] = 0;
                visited[i][j] = 0;
            }
        }
    }

    return 0;
}