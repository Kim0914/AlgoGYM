#include <iostream>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N, M, K;
int A[101][101];
int B[101][101];
int C[101][101];

void mul(int x, int y){
    FOR(i,1,M+1){
        C[x][y] += A[x][i] * B[i][y];
    }
}

int main(void){
    cin >> N >> M;
    FOR(i,1,N+1){
        FOR(j,1,M+1){
            cin >> A[i][j];
        }
    }
    cin >> M >> K;
    FOR(i,1,M+1){
        FOR(j,1,K+1){
            cin >> B[i][j];
        }
    }

    FOR(i,1,N+1){
        FOR(j,1,K+1){
            mul(i,j);
        }
    }

    FOR(i,1,N+1){
        FOR(j,1,K+1){
            cout << C[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}