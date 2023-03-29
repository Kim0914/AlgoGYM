#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    int end = *max_element(stones.begin(), stones.end());
    int start = *min_element(stones.begin(), stones.end());
    while(start <= end){
        int mid = (end + start) / 2;
        vector<int> t_stone (stones);
        int max_jump_count = 0;
        int temp_jump_count = 0;
        for(int i = 0; i < stones.size(); i++){
            t_stone[i] -= mid;
            if(t_stone[i] < 0){
                temp_jump_count++;
            }
            else{
                temp_jump_count = 0;
            }
            max_jump_count = max(max_jump_count, temp_jump_count);
        }
        if(max_jump_count < k){
            answer = max(mid, answer);
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    
    return answer;
}
