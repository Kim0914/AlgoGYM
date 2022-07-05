#include <vector>
#include <set>
using namespace std;

vector<string> temp;
set<string> fir_filter;
set<set<string>> sec_filter;
void cmp(vector<vector<string>> &table, vector<string> user_id, vector<string> banned_id, int idx) {
    for (int i = 0; i < user_id.size(); i++) {
        bool is_banned = true;
        for (int j = 0; j < banned_id[idx].size(); j++) {
            if (banned_id[idx].size() != user_id[i].size()) {
                is_banned = false;
                break;
            }
            if (banned_id[idx][j] == '*') continue;
            if (banned_id[idx][j] != user_id[i][j]) {
                is_banned = false;
                break;
            }
        }
        if (is_banned) table[idx].push_back(user_id[i]);
    }
}

void make_table(vector<vector<string>>& table, vector<string> user_id, vector<string> banned_id) {
    for (int i = 0; i < table.size(); i++)
        cmp(table, user_id, banned_id, i);
}

bool validate(string str) {
    for (auto i : temp)
        if (i == str) return false;
    return true;
}

void backtrack(int depth, vector<vector<string>> table, vector<vector<bool>>& visit) {
    if (depth == table.size()) {
        fir_filter.clear();
        for (auto i : temp)
            fir_filter.insert(i);

        if (fir_filter.size() == table.size()) 
            sec_filter.insert(fir_filter);

        return;
    }

    for (int i = 0; i < table[depth].size(); i++) {
        if (!visit[depth][i]) {
            visit[depth][i] = true;
            if (!validate(table[depth][i])) {
                visit[depth][i] = false; 
                continue;
            }
            temp.push_back(table[depth][i]);
            backtrack(depth + 1, table, visit);
            visit[depth][i] = false;
            temp.pop_back();
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    vector<vector<string>> table(banned_id.size());

    make_table(table, user_id, banned_id);
    vector<vector<bool>> visit(table.size(), vector<bool>(table[0].size(), false));

    backtrack(0, table, visit);

    answer = sec_filter.size();
    return answer;
}
