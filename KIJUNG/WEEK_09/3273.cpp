#include <iostream>
#include <vector>
#include <algorithm>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int n, x, cnt, tmp;
vector<int> nums;

int main(void){
    cin >> n;
    nums.push_back(0);

    FOR(i,0,n){
        cin >> tmp;
        nums.push_back(tmp);
    }
    sort(nums.begin(), nums.end());
    cin >> x;

    int left = 1;
    int right = n;

    while(left<right){
        int cur = nums[left] + nums[right];
        if( cur == x){
            cnt++;
            left++;
            right--;
        }
        else if(cur < x) left++;
        else right--;
    }

    cout << cnt;

    return 0;
}