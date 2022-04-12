#include <iostream>

using namespace std;

long long N, K, A, B, Bp;
long long mod = 1000000007;

long long pow(long long a, long long b){
    if(b==0) return 0;
    else if(b==1) return a;

    if(b%2==1) return pow(a,b-1)*a %mod;

    long long half = pow(a,b/2)%mod;
    return half*half %mod;
}

int main(void){

    cin >> N >> K;

    A=1;
    B=1;

    for(int i=N;i>=N-K+1;i--) A = (A*i)%mod;
    for(int i=K;i>=1;i--) B = (B*i)%mod;

    Bp = pow(B, mod-2);

    cout << A*Bp%mod;

    return 0;
}