#include <iostream>

#define FOR(i,a,b) for(int i = a;i < b; i++)

using namespace std;

int N, nums[1000001], before[1000001];

int main(void){
    cin >> N;

    nums[1] = 0;

    FOR(i,2,N+1){
        nums[i] = nums[i-1] + 1;
        before[i] = i-1;
        
        if(i%2==0) {
            if(nums[i/2]+1 < nums[i]){
                nums[i] = nums[i/2]+1;
                before[i] = i/2;
            }
        }
        if(i%3==0) {
            if(nums[i/3]+1 < nums[i]){
                nums[i] = nums[i/3]+1;
                before[i] = i/3;
            }
        }
    }

    cout << nums[N] << "\n";

    int cur = N;
    while(cur != 0){
        cout << cur << " ";
        cur = before[cur];
    }

    return 0;
}