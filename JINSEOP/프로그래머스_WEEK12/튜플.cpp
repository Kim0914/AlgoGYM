#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> tuples;
bool cmp(vector<int> &a, vector<int> &b) {
    return a.size() < b.size();
}

void parse_tuple(string s) {
    bool is_start = false, is_end = false;
    vector<int> temp_vec;
    string temp = "";

    for (char c : s) {
        if (c == '{')
            is_start = true;
        if (c == '}') {
            is_start = false;
            is_end = true;
        }

        if (is_start) {
            if ('0' <= c && c <= '9') {
                temp += c;
            }
            if (c == ',') {
                temp_vec.push_back(stoi(temp));
                temp = "";
            }
        }
        if (is_end) {
            if(temp != "") temp_vec.push_back(stoi(temp));
            tuples.push_back(temp_vec);
            temp = ""; is_end = false; temp_vec.clear();
        }
    }
}

bool validate(int i, vector<int> answer) {
    for (auto num : answer)
        if (i == num)
            return false;
    return true;
}

void remove_duplication(vector<int>& answer) {
    for (auto tup : tuples) {
        for (int i : tup) {
            if (validate(i, answer)) {
                answer.push_back(i);
            }
        }
    }
}

vector<int> solution(string s) {
    vector<int> answer;

    parse_tuple(s);
    sort(tuples.begin(), tuples.end(), cmp);
    remove_duplication(answer);

    return answer;
}
