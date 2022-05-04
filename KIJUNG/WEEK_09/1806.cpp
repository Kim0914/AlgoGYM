#include <iostream>
#include <algorithm>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N, S, sum, nums[100001];
int ans = 100001;

int main(void){
    cin >> N >> S;
    FOR(i,0,N){
        cin >> nums[i];
    }

    int point1=0;
    int point2=0;
    sum = nums[0];

    while(point1 < N && point2 < N){
        if(sum<S){
            sum += nums[++point2];
        }
        else {
            ans = min(point2-point1, ans);
            sum -= nums[point1++];
        }
    }
    if(ans == 100001) cout << 0;
    else cout << ans+1;

    return 0;
}