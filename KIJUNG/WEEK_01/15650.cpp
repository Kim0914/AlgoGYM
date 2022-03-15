#include <iostream>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N, M;
int num[8] = {0,};

void bt(int n, int k){
    if(k == M){
        FOR(i,0,M){
            cout << num[i] << ' ';
        }
        cout << '\n';
    }
    FOR(i,n,N){
        num[k] = i+1;
        bt(i+1,k+1);
    }
}


int main(void){

    cin >> N >> M;

    bt(0,0);
    
    return 0;
}