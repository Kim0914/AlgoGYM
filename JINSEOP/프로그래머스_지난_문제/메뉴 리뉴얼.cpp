#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<string, int> counter;
string comb = "";
void backtrack(string s, int course, int idx) {
    if (s.size() < course) return;

    if (comb.size() == course) {
        string temp = comb;
        sort(temp.begin(), temp.end());
        counter[temp]++;
        return;
    }

    for (int i = idx; i < s.size(); i++) {
        comb += s[i];
        backtrack(s, course, i + 1);
        comb.pop_back();
    }
}

void parse_orders(vector<string> orders, vector<int> course) {
    for (int i = 0; i < course.size(); i++)
        for(int j = 0; j < orders.size(); j++)
            backtrack(orders[j], course[i], 0);
}

void find_best_course(vector<int> course, vector<string>& answer) {
    for (int i = 0; i < course.size(); i++) {
        int max_v = 0;
        string best = "";
        for (auto menu : counter) {
            if (menu.first.size() != course[i]) continue;

            if (max_v < menu.second) {
                max_v = menu.second;
            }
        }

        for (auto menu : counter) {
            if (menu.first.size() != course[i]) continue;

            if (menu.second == max_v && max_v >= 2) {
                answer.push_back(menu.first);
            }
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    parse_orders(orders, course);
    find_best_course(course, answer);
    sort(answer.begin(), answer.end());

    return answer;
}
