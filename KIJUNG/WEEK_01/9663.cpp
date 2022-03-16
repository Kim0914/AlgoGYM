#include <iostream>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N;
int cnt = 0;
int cross1[27] = {0,};
int cross2[27] = {0,};
int vertical[14] = {0,};

void bt(int j){
    if(j == N){
        cnt++;
        return;
    }

    FOR(i,0,N){
        if(vertical[i] == 0 && cross1[i+j] == 0 && cross2[i-j+N] == 0){
            vertical[i] = 1;
            cross1[i+j] = 1;
            cross2[i-j+N] = 1;
            bt(j+1);
            vertical[i] = 0;
            cross1[i+j] = 0;
            cross2[i-j+N] = 0;
        }
    }
}

int main(void){

    cin >> N;
    bt(0);
    cout << cnt;

    return 0;
}