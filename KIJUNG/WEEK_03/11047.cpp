#include <iostream>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N, K;
int val[11];
int cnt;
int main(void){
    cin >> N >> K;

    FOR(i,1,N+1){
        cin >> val[i];
    }

    for(int i=N; i>0; i--){
        if(K/val[i] != 0){
            cnt += K/val[i];
            K = K%val[i];
        }
    }
    cout << cnt;

    return 0;
}