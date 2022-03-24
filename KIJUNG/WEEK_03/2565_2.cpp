#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

#define FOR(i,a,b) for(int i = a; i<b; i++)

using namespace std;

int N;
pair<int, int> line[101];
int dp[101];
int delCnt = 0;

int main(void){
    cin >> N;
    FOR(i,1,N+1){
        cin >> line[i].first >> line[i].second;
    }

    sort(line+1, line+N+1);
    fill(dp,dp+N,1);

    FOR(i,1,N+1){
        for(int j=i-1;j>0;j--){
            if(line[i].second > line[j].second){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        delCnt = max(dp[i],delCnt);
    }
    cout << N - delCnt;

    return 0;
}