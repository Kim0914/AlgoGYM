#include <iostream>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

long long N;
long long result[2][2] = {{1,0},{0,1}};
long long arr[2][2] = {{1,1},{1,0}};
int mod = 1000000007;

void dc(long long a1[2][2],long long a2[2][2]){
    long long tmp[2][2] = {0,};

    FOR(i,0,2){
        FOR(j,0,2){
            FOR(k,0,2){
                tmp[i][j] += a1[i][k] * a2[k][j];
            }
            tmp[i][j] %= mod; 
        }
    }

    FOR(i,0,2){
        FOR(j,0,2){
            a1[i][j] =  tmp[i][j];
        }
    }

}

int main(void){

    cin >> N;

    while(N){
        if(N%2 == 1){
            dc(result, arr);
            N--;
            continue;
        }
        dc(arr,arr);
        N = N/2;
    }

    cout << result[0][1];

    return 0;
}