#include <iostream>
#include <algorithm>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N,M,tmp;
int wei[31];
bool dp[32][15001];

void sol(int i, int target){
    if(i>N+1 || dp[i][target]) return;
    dp[i][target] = true;
    sol(i+1, target+wei[i]);
    sol(i+1, abs(target-wei[i]));
    sol(i+1, target);
}

int main(void){
    cin >> N;
    FOR(i,1,N+1){
        cin >> wei[i];
    }

    sol(1,0);

    cin >> M;

    FOR(i,0,M){
        cin >> tmp;
        if(tmp>15000) cout << "N ";
        else if(dp[N+1][tmp]) cout << "Y ";
        else cout << "N ";
    }

    return 0;
}