#include <iostream>
#include <algorithm>
#include <stack>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N, nums[1001], dp[1001], before[1001];
stack<int> s;

int main(void){
    cin >> N;

    FOR(i,0,N){
        cin >> nums[i];
        dp[i] = 1;
        before[i] = -1;
    }

    FOR(i,1,N){
        for(int j = i-1; j>=0; j--){
            if(nums[i]>nums[j]){
                if(dp[j]+1> dp[i]){
                    dp[i] = dp[j]+1;
                    before[i] = j;
                }
            }
        }
    }
    
    cout << *max_element(dp, dp+N) << "\n";
    int cur = (max_element(dp, dp+N) - dp);
    while(cur != -1){
        s.push(nums[cur]);
        cur = before[cur];
    }   

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}