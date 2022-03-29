#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, tmp;
vector<int> nums;

int main(void){
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> tmp;
        nums.push_back(tmp);
    }

    sort(nums.begin(), nums.end());
    cout << nums[0]*nums[N-1];

    return 0;
}