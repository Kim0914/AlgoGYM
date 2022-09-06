#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void territory_occupation(vector<vector<int>>& land) {
    for (int row = 1; row < land.size(); row++) {
        for (int col = 0; col < 4; col++) {
            switch (col)
            {
            case 0:
                land[row][col] += max(land[row - 1][1], max(land[row - 1][2], land[row - 1][3]));
                break;
            case 1:
                land[row][col] += max(land[row - 1][0], max(land[row - 1][2], land[row - 1][3]));
                break;
            case 2:
                land[row][col] += max(land[row - 1][0], max(land[row - 1][1], land[row - 1][3]));
                break;
            case 3:
                land[row][col] += max(land[row - 1][0], max(land[row - 1][1], land[row - 1][2]));
                break;
            }
        }
    }
}

int solution(vector<vector<int>> land){
    int answer = 0;

    territory_occupation(land);
    answer = *max_element(land[land.size() - 1].begin(), land[land.size() - 1].end());

    return answer;
}
