#include<iostream>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int T, tmp;
int dp[41]= {0,};

int fibonacci(int n){
    if(n == 0){
        return 0;
    }
    else if(n == 1){
        return 1;
    }

    if (dp[n] == 0) dp[n] = fibonacci(n-1) + fibonacci(n-2);
    return dp[n];
}

int main(void){
    cin >> T;

    dp[0] = 0;
    dp[1] = 1;

    FOR(i,0,T){
        cin >> tmp;
        if(tmp == 0) cout << "1 0\n";
        else if(tmp == 1) cout << "0 1\n";
        else{
            fibonacci(tmp);
            cout << fibonacci(tmp-1) << " " << fibonacci(tmp) << "\n";
        }
    }

    return 0;
}