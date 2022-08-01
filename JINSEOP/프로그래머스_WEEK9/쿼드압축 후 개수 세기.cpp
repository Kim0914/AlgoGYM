#include <string>
#include <vector>
using namespace std;

void compress(int x, int y, int arr_size, vector<vector<int>>& arr, vector<int>& answer) {
    bool is_zero = true, is_one = true;
    
    for (int i = x; i < x + arr_size; i++) {
        for (int j = y; j < y + arr_size; j++) {
            if (arr[i][j] == 0) is_one = false;
            if (arr[i][j] == 1) is_zero = false;
        }
    }

    if (is_zero == true) {
        answer[0]++;
        return;
    }
    
    if (is_one == true) {
        answer[1]++;
        return;
    }

    compress(x, y, arr_size/2, arr, answer);
    compress(x, y + arr_size / 2, arr_size/2, arr, answer);
    compress(x + arr_size / 2, y + arr_size/2, arr_size / 2, arr, answer);
    compress(x + arr_size /2 , y, arr_size / 2, arr, answer);
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2, 0);

    compress(0, 0, arr.size(), arr, answer);
    return answer;
}

// 반드시 &arr로 넘겨주자.
// 안그럼 시간초과 남!
