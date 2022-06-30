#include <vector>
#include <unordered_set>
using namespace std;

unordered_set<int> classifier;
int solution(vector<int> nums)
{
    int answer = 0;
    int limit = nums.size() / 2;
    
    for (int i = 0; i < nums.size(); i++)
        classifier.insert(nums[i]);

    if (classifier.size() > limit) answer = limit;
    else answer = classifier.size();
    
    return answer;
}
