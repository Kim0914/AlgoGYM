#include <string>
#include <vector>
using namespace std;

bool find_key = false;

void expand_lock(vector<vector<int>> lock, vector<vector<int>>& ex_lock) {
    int addit = ex_lock.size() - lock.size();
    for (int i = 0; i < ex_lock.size(); i++) {
        for (int j = 0; j < ex_lock.size(); j++) {
            if((i >= addit && j >= addit))
                ex_lock[i][j] = lock[i - addit][j - addit];
        }
    }
}

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

int is_key(int st_x, int st_y, int org_lock, vector<vector<int>> key, vector<vector<int>> ex_lock) {
    int sum = 0, temp = st_y;
    int addit = ex_lock.size() - org_lock;

    for (int i = 0; i < key.size(); i++) {
        if (st_x < addit) { st_x++; continue; }
        if (st_x > ex_lock.size() - 1) break;
        st_y = temp;
        for (int j = 0; j < key.size(); j++) {
            if (st_y < addit) { st_y++; continue; }
            if (st_y > ex_lock.size() - 1) break;
            ex_lock[st_x][st_y] ^= key[i][j];
            st_y++;
        }
        st_x++;
    }

    for (int i = addit; i < ex_lock.size(); i++) {
        for (int j = addit; j < ex_lock.size(); j++) {
            sum += ex_lock[i][j]++;
        }
    }

    if (sum == org_lock * org_lock) return true;
    else return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    vector<vector<int>> ex_lock(lock.size() + (key.size() - 1), vector<int>(lock.size() + (key.size() - 1)));

    expand_lock(lock, ex_lock);

    for (int i = 0; i < ex_lock.size(); i++) {
        if (find_key) break;
        for (int j = 0; j < ex_lock.size(); j++) {
            if (find_key) break;
            for (int rot = 0; rot < 4; rot++) {
                if (is_key(i, j, lock.size(), key, ex_lock)) { find_key = true;  break; }
                rot_clock(key);
            }
        }
    }
    
    if (find_key) answer = true;
    else answer = false;
    
    return answer;
}
