#include <iostream>
#include <vector>
using namespace std;

int trans_cnt = 0, min_v = 9999999;
bool is_exist(string target, vector<string> words) {
    for (auto s : words)
        if (target == s) return true;

    return false;
}

bool validate(string src, string dest) {
    int diff_cnt = 0;

    for (int i = 0; i < src.size(); i++)
        if (src[i] != dest[i])
            diff_cnt++;

    if (diff_cnt == 1) return true;
    else return false;
}

void backtrack(int idx, string src, string target, vector<string> words, vector<bool>& visit) {
    if (src == target) {
        min_v = trans_cnt;
        return;
    }

    if (trans_cnt > min_v) return;
    if (idx == words.size()) return;

    for (int i = 0; i < words.size(); i++) { // 이 부분은 왜 0부터 시작을 해야만 통과가 가능한가?
        if (!visit[i]) { // 만약 0부터 시작하지 않고 내가 저장한 i부터 시작하면, 이전의 분기로 Backtrack 할 수 없다!
                         // 0부터 뒤져서 해제된 visit을 찾아서 Backtrack 하는 원리니까!
            if (validate(src, words[i])) {
                visit[i] = true;
                trans_cnt++;
                backtrack(i, words[i], target, words, visit);
                trans_cnt--;
                visit[i] = false;
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    vector<bool> visit(words.size(), 0);

    if (!is_exist(target, words)) return 0;
    backtrack(0, begin, target, words, visit);
    answer = min_v;

    return answer;
}

int main() {
    vector<string> words = { "hot", "dot", "dog", "lot", "log" };
    cout << solution("hit", "cog", words);
    return 0;
}

// 백트래킹의 변형 문제.
