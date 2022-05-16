#include <iostream>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int T, N, M, tmp;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    FOR(i,0,T){
        cin >> N >> M;
        FOR(j,0,M) cin >> tmp >> tmp;
        cout << N-1 << "\n";
    }
    return 0;
}