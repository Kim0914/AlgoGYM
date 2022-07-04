#include <vector>
using namespace std;

int solution(vector<int> nums)
{
    int length = nums.size();
    vector<int> ans;
    int idx = 0;
    for(int i = 0; i < length; i++){
        bool flag = true;
        for(int j = 0; j < ans.size();j++){
            if(ans[j] == nums[i]){
                flag = false;
                break;
            }
        }
        if(flag){
            ans.push_back(nums[i]);
        }
    }
    if(ans.size() > length / 2) return length/2;
    else return ans.size();
}
