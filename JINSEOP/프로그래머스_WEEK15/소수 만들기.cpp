#include <vector>
#include <string>
#include <cmath>
using namespace std;

int sum = 0, cnt = 0;
bool validate(int n) {
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;

    return true;
}

void backtrack(int depth, int idx, vector<int> nums, vector<bool>& visit) {
    if (depth == 3) {
        if (validate(sum))
            cnt++;

        return;
    }

    for (int i = idx; i < nums.size(); i++) {
        if (!visit[i]) {
            sum += nums[i];
            visit[i] = true;
            backtrack(depth + 1, i, nums, visit);
            sum -= nums[i];
            visit[i] = false;
        }
    }
}

int solution(vector<int> nums) {
    int answer = -1;
    
    vector<bool> visit(nums.size(), 0);
    backtrack(0, 0, nums, visit);

    answer = cnt;
    return answer;
}
