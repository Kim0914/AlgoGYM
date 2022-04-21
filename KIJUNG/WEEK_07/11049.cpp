#include <iostream>
#include <algorithm>

using namespace std;

int N;
int nums[501][2];
int dp[501][501];

int main(void){
    cin >> N;

    for(int i =1; i<=N;i++){
        cin >> nums[i][0] >> nums[i][1];
    }

    for(int i=1;i<=N;i++){ //i는 크기를 의미
        for(int j=1;j+i<=N;j++){ // j는 시작점
            dp[j][j+i] = 2000000000;
            for(int k=j+1;k<=j+i;k++){
                dp[j][j+i] = min(dp[j][j+i], dp[j][k-1]+ dp[k][j+i] +(nums[j][0]*nums[k-1][1]*nums[j+i][1]));
            }
        }       
    }

    cout << dp[1][N];

    return 0;
}