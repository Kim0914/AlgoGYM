#include <iostream>

using namespace std;

long long A, B, C;

long long pow(long long a, long long b){
    if(b==0) return 0;
    else if(b==1) return a;

    if(b%2==1) return pow(a,b-1) * a%C;
    
    long long half = pow(a,b/2)%C;
    return (half*half)%C;
}

int main(void){

    cin >> A >> B >> C;

    cout << pow(A,B)%C;

    return 0;
}