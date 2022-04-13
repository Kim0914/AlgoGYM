#include <iostream>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

long long N, B;
long long result[5][5];
long long arr[5][5];

void mul(long long a1[5][5], long long a2[5][5]){
    long long tmp[5][5] = {0,};
    FOR(i,0,N){
        FOR(j,0,N){
            FOR(k,0,N){
                tmp[i][j] += a1[i][k] * a2[k][j];
            }
            tmp[i][j] %= 1000;
        }
    }
    
    FOR(i,0,N){
        FOR(j,0,N){
            a1[i][j] = tmp[i][j];
        }
    }
}


int main(void){
    cin >> N >> B;
    
    //input
    FOR(i,0,N){
        FOR(j,0,N){
            cin >> arr[i][j];
        }    
        result[i][i] = 1;   
    }

    //logic
    while(B){
        if(B%2 == 1){
            mul(result, arr);
            B--;
        }else{
            mul(arr, arr);
            B = B/2;
        }
    }

    FOR(i,0,N){
        FOR(j,0,N){
            cout << result[i][j] << " ";
        }    
        cout << "\n";
    }

    return 0;
}