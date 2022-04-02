#include <iostream>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N, K;

int pe[1002][1002];

int main(void){

    cin >> N >> K;

    FOR(i,1,N+1){
        FOR(j,0,i+1){
            if(j == 0 || i==j) pe[i][j] = 1;
            else pe[i][j] = (pe[i-1][j-1] + pe[i-1][j])%10007;
            cout << pe[i][j] << " ";
        }
        cout << "\n";
    }

    cout << pe[N][K];


    return 0;
}