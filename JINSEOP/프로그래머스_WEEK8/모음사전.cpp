#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool is_end = false;
int cnt = 0;
string res;

void backtrack(int depth, vector<bool>& visit, string keyword, string word) {
    if (depth > 5) return;

    if (res == word) {
        is_end = true;
        return;
    }

    if (is_end) return;
    cnt++;

    for (int i = 0; i < keyword.size(); i++) {
            res += keyword[i];
            backtrack(depth + 1, visit, keyword, word);
            res.pop_back();
    }
}

int solution(string word) {
    int answer = 0;
    string keyword = "AEIOU";
    vector<bool> visit(5, 0);

    backtrack(0, visit, keyword, word);

    answer = cnt;
    return answer;
}
