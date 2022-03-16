#include <iostream>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N,M;
int num[8] = {0,};

void bt(int degit, int start){
    if(degit == M){
        FOR(i,0,M){
            cout << num[i] << ' ';
        }
        cout << "\n";
        return;
    }

    for(int i=start; i<N; i++){
        num[degit] = i+1;
        bt(degit+1,i);
    }
}

int main(void){

    cin >> N >> M;

    bt(0,0);

    return 0;
}