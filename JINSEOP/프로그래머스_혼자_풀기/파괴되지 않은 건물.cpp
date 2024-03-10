#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;

    // 그냥 구현할 경우 반드시 시간초과 발생
    for (auto infos : skill) {
        if (infos[0] == 1) {
        // 지형 파괴
            for (int i = infos[1]; i <= infos[3]; i++)
                for (int j = infos[2]; j <= infos[4]; j++)
                    board[i][j] -= infos[5];
        }
        else {
        // 지형 회복
            for (int i = infos[1]; i <= infos[3]; i++)
                for (int j = infos[2]; j <= infos[4]; j++)
                    board[i][j] += infos[5];
        }
    }

    for (int i = 0; i < board.size(); i++)
        for (int j = 0; j < board[0].size(); j++)
            if (board[i][j] > 0)
                answer++;
    // 살아있는 지형 카운트

    return answer;
}
