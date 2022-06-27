#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool find_key = false;

void rot_clock(vector<vector<int>>& key) {
    int limit = key.size();
    vector<vector<int>> temp(limit, vector<int>(limit, 0));
    for (int i = 0; i < limit; i++) {
        for (int j = 0; j < limit; j++) {
            temp[i][j] = key[(limit - 1) - j][i];
        }
    }

    key = temp;
}

int is_key(int st_x, int st_y, vector<vector<int>> key, vector<vector<int>> lock) {
    int sum = 0, temp = st_y, cnt = 0;

    for (int i = 0; i < key.size(); i++) {
        if (st_x > lock.size() - 1) break;
        st_y = temp;
        for (int j = 0; j < key.size(); j++) {
            if (st_y > lock.size() - 1) break;
            sum += lock[st_x][st_y] ^ key[i][j];
            st_y++; cnt++;
        }
        st_x++;
    }

    if (cnt == sum) return true;
    else return false;
}

int main() {
    vector<vector<int>> key = { {0,0,0}, {1,0,0}, {0,1,1} };
    vector<vector<int>> lock = { {1,1,1}, {1,1,0}, {1,0,1} };

    for (int i = 0; i < lock.size(); i++) {
        if (find_key) break;
        for (int j = 0; j < lock.size(); j++) {
            if (find_key) break;
            for (int rot = 0; rot < 4; rot++) {
                if (is_key(i, j, key, lock)) { find_key = true;  break; }
                rot_clock(key);
            }
        }
    }
    if (find_key) cout << "true";
    else cout << "false";

    return 0;
}
