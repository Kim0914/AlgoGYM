#include <iostream>
#include <algorithm>
#include <math.h>

#define FOR(i,a,b) for(int i=a;i<b; i++)

using namespace std;

int N;
int point[20][20];
bool team[20];
int m = 1000000000;

void bt(int cnt, int cur){
    if(cnt == N/2){ // 종료조건
        int start = 0;
        int link = 0;

        FOR(i,0,N){
            FOR(j,0,N){
                if(team[i] && team[j]) start += point[i][j];
                if(!(team[i] || team[j])) link += point[i][j];
            }
        }
        m = min(m, abs(start-link));
        return;
    }

    FOR(i,cur,N-1){ //다음 인덱스
        team[i] = true;
        bt(cnt+1,i+1);
        team[i] = false;
    }
}

int main(void){

    cin>> N;

    FOR(i,0,N){
        FOR(j,0,N){
            cin >> point[i][j];
        }
    }

    bt(0,0);

    cout << m;

    return 0;
}