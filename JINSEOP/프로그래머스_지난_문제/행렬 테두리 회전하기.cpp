#include <string>
#include <vector>
using namespace std;
#define BIGINT 9999999

vector<vector<int>> board;
void make_board(int rows, int columns) {
    int cnt = 1;

    for (int i = 0; i < rows; i++) {
        vector<int> temp;
        for (int j = 0; j < columns; j++)
            temp.push_back(cnt++);
        board.push_back(temp);
    }
}

int find_min(vector<int> query) {
    int min_v = BIGINT;

    for (int i = query[1] - 1; i < query[3]; i++) {
        if (min_v > board[query[0] - 1][i])
            min_v = board[query[0] - 1][i];
    }
    for (int i = query[0] - 1; i < query[2]; i++) {
        if (min_v > board[i][query[3] - 1])
            min_v = board[i][query[3] - 1];
    }
    for (int i = query[1] - 1; i < query[3]; i++) {
        if (min_v > board[query[2] - 1][i])
            min_v = board[query[2] - 1][i];
    }
    for (int i = query[0] - 1; i < query[2]; i++) {
        if (min_v > board[i][query[1] - 1])
            min_v = board[i][query[1] - 1];
    }

    return min_v;
}

void rotate_matrix(vector<vector<int>> queries, vector<int>& answer) {
    for (int k = 0; k < queries.size(); k++) {
        int pv = board[queries[k][0] - 1][queries[k][3] - 1];
        for (int i = queries[k][3] - 1; i > queries[k][1] - 1; i--) {
            board[queries[k][0] - 1][i] = board[queries[k][0] - 1][i - 1];
        }

        int nx = board[queries[k][2] - 1][queries[k][3] - 1];
        for (int i = queries[k][2] - 1; i > queries[k][0] - 1; i--) {
            board[i][queries[k][3] - 1] = board[i - 1][queries[k][3] - 1];
            if (i == queries[k][0]) board[i][queries[k][3] - 1] = pv;
        }

        pv = nx;
        nx = board[queries[k][2] - 1][queries[k][1] - 1];
        for (int i = queries[k][1] - 1; i < queries[k][3] - 1; i++) {
            board[queries[k][2] - 1][i] = board[queries[k][2] - 1][i + 1];
            if (i == queries[k][3] - 2) board[queries[k][2] - 1][i] = pv;
        }
 
        pv = nx;
        for (int i = queries[k][0] - 1; i < queries[k][2] - 1; i++) {
            board[i][queries[k][1] - 1] = board[i + 1][queries[k][1] - 1];
            if (i == queries[k][2] - 2) board[i][queries[k][1] - 1] = pv;
        }

        answer.push_back(find_min(queries[k]));
    }
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;

    make_board(rows, columns);
    rotate_matrix(queries, answer);

    return answer;
}
