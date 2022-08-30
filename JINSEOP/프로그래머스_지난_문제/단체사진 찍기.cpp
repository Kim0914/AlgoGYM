#include <string>
#include <vector>
using namespace std;
#define KAKAOS 8

bool validate(char oper, int limit, int dist) {
    switch (oper) {
    case '=':
        return limit == dist;
    case '>':
        return limit < dist;
    case '<':
        return limit > dist;
    }
}

void backtrack(vector<string> data, char friends[], string& friend_seq, bool visit[], int& answer) {
    if (friend_seq.size() == KAKAOS) {
        bool is_possible = true;
        for (string d : data) {
            int st_idx = friend_seq.find(d[0]);
            int end_idx = friend_seq.find(d[2]);
            int dist = abs(st_idx - end_idx) - 1;
            int limit = d[4] - '0';

            if (!validate(d[3], limit, dist)) {
                is_possible = false;
                break;
            }
        }

        if (is_possible) answer++;
        return;
    }

    for (int i = 0; i < KAKAOS; i++) {
        if (!visit[i]) {
            visit[i] = true;
            friend_seq += friends[i];
            backtrack(data, friends, friend_seq, visit, answer);
            visit[i] = false;
            friend_seq.pop_back();
        }
    }
}

int solution(int n, vector<string> data) {
    int answer = 0;
    char friends[KAKAOS] = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };
    bool visit[KAKAOS] = { 0, };
    string friend_seq = "";

    backtrack(data, friends, friend_seq, visit, answer);
    return answer;
}
