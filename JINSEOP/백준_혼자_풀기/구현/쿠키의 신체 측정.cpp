#include <iostream>
using namespace std;

int num = 0, waist = 0;
char cookie_board[1001][1001];
pair<int, int> head_pos, heart_pos, arm_length, leg_length;
void optimize() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void read_head() {
    for (int i = 1; i <= num; i++)
        for (int j = 1; j <= num; j++)
            if (cookie_board[i][j] == '*') {
                head_pos = { i, j };
                heart_pos = { i + 1, j };
                return;
            }
}

void read_arm() {
    for (int i = 1; i <= num; i++) {
        if (i == heart_pos.second)
            continue;

        if (cookie_board[heart_pos.first][i] == '*' && i < heart_pos.second)
            arm_length.first++;
        if (cookie_board[heart_pos.first][i] == '*' && i > heart_pos.second)
            arm_length.second++;
    }
}

void read_waist() {
    for (int i = heart_pos.first + 1; i <= num; i++) {
        if (cookie_board[i][heart_pos.second] == '*')
            waist++;
    }
}

void read_leg() {
    for (int i = heart_pos.first + waist; i <= num; i++) {
        if (cookie_board[i][heart_pos.second - 1] == '*')
            leg_length.first++;
        if (cookie_board[i][heart_pos.second + 1] == '*')
            leg_length.second++;
    }
}

void read_cookie() {
    read_head();
    read_arm();
    read_waist();
    read_leg();
}

int main() {
    optimize();
    
    cin >> num;
    for (int i = 1; i <= num; i++)
        for (int j = 1; j <= num; j++)
            cin >> cookie_board[i][j];

    read_cookie();
    cout << heart_pos.first << " " << heart_pos.second << '\n';
    cout << arm_length.first << " " << arm_length.second << " " << waist << " " << leg_length.first << " " << leg_length.second << '\n';
    return 0;
}
