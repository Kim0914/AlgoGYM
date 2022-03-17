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

//백트레킹의 전형적인 문제다.

//백트레킹: 가능한 모든 경우의 수 중에서 특정 조건을 만족하는 경우만 살펴보는방식.
//해가 될 가능성이 있으면 다음노드로 탐색을 이어나가고, 가망이 없으면 가지치기를 통해서 이전 노드로 돌아간다.

//가지치기를 얼마나 잘하는냐가(조건을 어떻게 걸 것인지, 어떤 조건으로 가능성을 판별할 것인지) 백트레킹 알고리즘의 효율을 결정한다.
//따라서 가능성을 판단하는 조건을 찾는 것이 핵심!!