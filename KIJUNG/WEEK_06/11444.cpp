#include <iostream>

using namespace std;

long long N;
long long fibo[18] = {0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1697};
long long mod = 1000000007;

long long bc(long long N){
    if(N<0){
        return 1;
    }
    if(N<=17){
        // cout << "0000";//

        return fibo[N];
    }
    return ((fibo[17] * bc(N-16)) % mod + (fibo[16] * bc(N-17)) % mod)%mod;
}


int main(void){
    cin >> N;

    cout << bc(N)%mod;




    return 0;
}