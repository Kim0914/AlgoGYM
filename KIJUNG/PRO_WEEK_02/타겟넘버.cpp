#include <vector>

using namespace std;
int answer;

void dfs(int idx, int sum, vector<int> &numbers, int target){
    if(idx>=numbers.size()) {
        if(sum == target) answer++;
        return;
    }
    dfs(idx+1, sum+numbers[idx], numbers, target);
    dfs(idx+1, sum-numbers[idx], numbers, target);
}

int solution(vector<int> numbers, int target) {
    dfs(1,numbers[0],numbers,target);
    dfs(1,-numbers[0],numbers,target);
    
    return answer;
}