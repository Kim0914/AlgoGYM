#include <iostream> 
#include <algorithm>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N, M;
int nums[2001];
bool dp[2002][2002];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    FOR(i,1,N+1){
        cin >> nums[i];
        dp[i][i] = true;
        if(nums[i-1] == nums[i]) dp[i-1][i] = true;
    }

    // main logic
    for(int i=1;i<=2*N;i++){
        if(i%2==1){
            int mid = i/2+1;
            for(int j=1;j<=i/2;j++){
                if(dp[mid-j+1][mid+j-1]) {
                    if(nums[mid-j]== nums[mid+j]) dp[mid-j][mid+j] = true;
                }
                else break;
            }
        }
        else{
            int mid = i/2;
            for(int j=1; j<i/2; j++){
                if(dp[mid-j+1][mid+j]){
                    if(nums[mid-j] == nums[mid+j-1]) dp[mid-j][mid+j+1] = true;
                }
                else break;
            }
        }
    }

    // output
    int t1,t2;
    cin >> M;
    FOR(i,0,M){
        cin >> t1 >> t2;
        cout << dp[t1][t2] << "\n";
    }

    return 0;
}