#include <iostream>

using namespace std;

int N, K;
long long store[2][4000001];
long long result = 0;

void bc(int n, int k){
    if(n<1) return;
    if (k==0) {
        store[0][n]++;
        return;
    }
    if (k==n) {
        store[1][n]++;
        return;
    }
    bc(n-1,k-1);
    bc(n-1,k);
}

int main(void){

    cin >> N >> K;

    bc(N,K);
    for(int i = 0;i<2;i++){
        for(int j =0;j<4000001;j++){
            result += store[i][j];
            if(result>=1000000007) result %= 1000000007;
        }
    }
    
    cout << result;

    return 0;
}