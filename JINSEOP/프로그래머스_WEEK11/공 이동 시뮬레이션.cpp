#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool move_ball(int st_x, int st_y, int dest_x, int dest_y, vector<vector<int>> queries, vector<vector<char>> maps) {
    int col_limit = maps[0].size();
    int row_limit = maps.size();

    maps[st_x][st_y] = 'P'; // init

    int new_x = st_x, new_y = st_y;
    int prev_x = st_x, prev_y = st_y;
    for (auto query : queries) {
        switch (query[0])
        {
        case 0:
            if (prev_y - query[1] >= 0) {
                new_x = prev_x;
                new_y = prev_y - query[1];
                swap(maps[prev_x][prev_y], maps[new_x][new_y]);
            }
            break;
        case 1:
            if (prev_y + query[1] < col_limit) {
                new_x = prev_x;
                new_y = prev_y + query[1];
                swap(maps[prev_x][prev_y], maps[new_x][new_y]);
            }
            break;
        case 2:
            if (prev_x - query[1] >= 0) {
                new_x = prev_x - query[1];
                new_y = prev_y;
                swap(maps[prev_x][prev_y], maps[new_x][new_y]);
            }
            break;
        case 3:
            if (prev_x + query[1] < row_limit) {
                new_x = prev_x + query[1];
                new_y = prev_y;
                swap(maps[prev_x][prev_y], maps[new_x][new_y]);
            }
            break;
        }
        prev_x = new_x; prev_y = new_y;
    }

    if (maps[dest_x][dest_y] == 'P') return true;
    else return false;
}

long long do_query(int n, int m, int x, int y, vector<vector<int>> queries, vector<vector<char>> maps) {
    long long answer = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (move_ball(i, j, x, y, queries, maps)) answer++;

    return answer;
}

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    long long answer = 0;

    vector<vector<char>> maps(n, vector<char>(m, '0'));
    answer = do_query(n, m, x, y, queries, maps);

    return answer;
}
