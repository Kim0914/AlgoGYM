#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums)
{
    set<int> s;
    
    for(int num: nums){
        s.insert(num);
    }
    if(s.size() >= nums.size()/2) return nums.size()/2;
    else return s.size();
}