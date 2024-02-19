#include <string>
#include <vector>
using namespace std;

bool check_stones(int target_friends, int limit, vector<int> stones) {
    int cnt = 0;

    for (int i = 0; i < stones.size(); i++) {
        if (stones[i] < target_friends) {
            cnt++;

            if (cnt >= limit)
                return false;
        }
        else
            cnt = 0;
    }

    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    
    int left = 0, right = 999999999;
    while (left <= right) {
        int mid = (left + right) / 2;

        if (check_stones(mid, k, stones)) {
            left = mid + 1;
            answer = mid;
        }
        else
            right = mid - 1;
    }

    return answer;
}

int main() {
    solution({ 2,4,5,3,2,1,4,2,5,1 }, 3);
	return 0;
}
