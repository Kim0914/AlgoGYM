#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void do_dp(vector<vector<int>>& triangle) {
    for (int i = 1; i < triangle.size(); i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            if (j == 0)
                triangle[i][j] += triangle[i - 1][j];
            else if (j == (triangle[i].size() - 1))
                triangle[i][j] += triangle[i - 1][j - 1];
            else
                triangle[i][j] = max(triangle[i][j] + triangle[i - 1][j - 1],
                                     triangle[i][j] + triangle[i-1][j]);
        }
    }
}

int find_max(vector<vector<int>>& triangle) {
    return *max_element(triangle[triangle.size() - 1].begin(), triangle[triangle.size() - 1].end());
}

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    do_dp(triangle);
    answer = find_max(triangle);
    return answer;
}
