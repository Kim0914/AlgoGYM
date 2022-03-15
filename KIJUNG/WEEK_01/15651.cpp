#include <iostream>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N, M;
int num[7] = {0,};

void bt(int digit){
    if(digit == M){
        FOR(i,0,M){
            cout << num[i] << ' ';
        }
        cout << '\n';
        return;
    }
    FOR(i,0,N){
        num[digit] = i+1;  
        bt(digit+1);
    }
}

int main(void){
    cin >> N >> M;
    bt(0);
    
    return 0;
}