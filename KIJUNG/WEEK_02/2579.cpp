#include <iostream>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N;
int stair[301];
int store[301][2];

int dp(int cur, bool possible){
    if(cur <= 0) return 0;

    if(possible){
        if(store[cur][1]!=0) return store[cur][1];
        return store[cur][1] = max(dp(cur-1, false), dp(cur-2, true)) + stair[cur];
    }else{
        if(store[cur][0]!=0) return store[cur][0];
        return store[cur][0] = dp(cur-2, true) + stair[cur];
    }
}

int main(void){
    cin>> N;
    FOR(i,1,N+1){
        cin >> stair[i];
    }

    dp(N, true);

    cout << store[N][1];

    return 0;
}