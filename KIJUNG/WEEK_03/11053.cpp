#include <iostream>
#include <algorithm>
#include <math.h>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N;
int nums[1001];
int dp[1001];

int main(void){
    cin >> N;

    FOR(i,1,N+1){
        cin >> nums[i];
    }

    fill(dp+1, dp+N+1, 1);

    FOR(i,2,N+1){
        for(int j=i-1; j>0; j--){
            if(nums[i]>nums[j]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }

    cout << *max_element(dp+1, dp+N+1);

    return 0;
}