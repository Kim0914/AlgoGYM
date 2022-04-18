#include <iostream>
#include <algorithm>
#include <vector>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N;
int nums[1000001];
vector<int> lis;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;

    FOR(i,1,N+1){
        cin >> nums[i];
    }

    lis.push_back(nums[1]);

    FOR(i,2,N+1){
        if(lis.back() < nums[i]){
            lis.push_back(nums[i]);
        }
        else{
            vector<int>:: iterator j = lower_bound(lis.begin(), lis.end(), nums[i]);
            *j = nums[i];
        }
    }

    cout << lis.size();

    return 0;
}