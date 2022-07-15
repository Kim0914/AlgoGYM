#include <string>
#include <vector>
#define INF 99999999
using namespace std;

int min_res = INF, cnt = 0;
bool is_there(string target, vector<string> words) {
    for (int i = 0; i < words.size(); i++)
        if (target == words[i]) return true;

    return false;
}

bool validation(string begin, string target) {
    int cnt = 0;

    for (int i = 0; i < begin.size(); i++)
        if (begin[i] != target[i]) cnt++;

    if (cnt == 1) return true;
    else return false;
}

void backtrack(int start, string begin, string target, vector<string> words, vector<bool>& visit) {
    if (begin == target) {
        min_res = cnt;
        return;
    }

    if (cnt > min_res) return;
    if (start == words.size()) return;

    for (int i = 0; i < words.size(); i++) {
        if (!visit[i]) {
            if (validation(begin, words[i])) {
                visit[i] = true;
                cnt++;
                backtrack(i, words[i], target, words, visit);
                visit[i] = false;
                cnt--;
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    vector<bool> visit(words.size(), 0);

    if (!is_there(target, words)) {}
    else {
        backtrack(0, begin, target, words, visit);
        answer = min_res;
    }

    return answer;
}
