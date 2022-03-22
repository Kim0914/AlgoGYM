#include <iostream>
#include <math.h>

#define FOR(i,a,b) for(int i = a;i < b; i++)

using namespace std;

int N;
int nums[1000001];

int main(void){
    cin >> N;

    nums[1] = 0;

    FOR(i,2,N+1){
        nums[i] = nums[i-1] + 1;
        if(i%2==0) nums[i] = min(nums[i/2]+1, nums[i]); 
        if(i%3==0) nums[i] = min(nums[i/3]+1, nums[i]);
    }

    cout << nums[N];

    return 0;
}
//단순하게 생각하자