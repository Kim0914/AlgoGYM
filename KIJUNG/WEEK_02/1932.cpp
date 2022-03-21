#include <iostream>
#include <math.h>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N;
int nums[501][501];

int main(void){
    cin >> N;

    FOR(i,1,N+1) FOR(j,1,i+1) {
        cin >> nums[i][j];
    }

    for(int i=N-1; i>=1; i--){
        for(int j=1; j<=i; j++){
            nums[i][j] += max(nums[i+1][j], nums[i+1][j+1]);
        }
    }

    cout << nums[1][1];

    return 0;
}