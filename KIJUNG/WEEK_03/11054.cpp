#include <iostream>
#include <algorithm>
#include <math.h>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N;
int nums[1001];
int dp1[1001];
int dp2[1001];

int main(void){
    cin >> N;
    
    FOR(i,1,N+1){
        cin >> nums[i];
    }

    fill(dp1+1, dp1+N+1,1);
    fill(dp2+1, dp2+N+1,1);

    FOR(i,2,N+1){
        for(int j=i-1; j>0; j--){
            if(nums[i] > nums[j]){
                dp1[i] = max(dp1[i], dp1[j]+1);
            }
        }
    }

    for(int i = N-1; i>0; i--){
        for(int j=i+1; j<N+1; j++){
            if(nums[i] > nums[j]){
                dp2[i] = max(dp2[i], dp2[j]+1);
            }
        }
    }

    int M = 1;
    FOR(i,1,N+1){
        M = max(M, dp1[i]+ dp2[i]-1);
        // cout << "i: " << i << " dp1[i]+ dp2[i]+1 : " << dp1[i]+ dp2[i]+1 << "\n"; 
        // cout << "i: " << i << " dp1[i]: " << dp1[i]; 
        // cout << " dp2[i]: " << dp2[i] << "\n"; 
    }

    cout << M;



    return 0;
}