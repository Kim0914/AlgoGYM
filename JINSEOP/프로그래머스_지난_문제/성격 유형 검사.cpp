#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<char, int> score_board;
void init_map() {
    score_board['R'] = 0; score_board['T'] = 0;
    score_board['C'] = 0; score_board['F'] = 0;
    score_board['J'] = 0; score_board['M'] = 0;
    score_board['A'] = 0; score_board['N'] = 0;
}

void likert_scale(vector<string> survey, vector<int> choices) {
    for (int i = 0; i < survey.size(); i++) {
        if (choices[i] == 4) continue;
        if (choices[i] > 4) score_board[survey[i][1]] += choices[i] - 4;
        if (choices[i] < 4) score_board[survey[i][0]] += 4 - choices[i];
    }
}

void make_mbti(string& answer) {
    for (int i = 0; i < answer.size(); i++) {
        switch (i)
        {
        case 0:
            if (score_board['R'] >= score_board['T']) answer[i] = 'R';
            else answer[i] = 'T';
            break;
        case 1:
            if (score_board['C'] >= score_board['F']) answer[i] = 'C';
            else answer[i] = 'F';
            break;
        case 2:
            if (score_board['J'] >= score_board['M']) answer[i] = 'J';
            else answer[i] = 'M';
            break;
        case 3:
            if (score_board['A'] >= score_board['N']) answer[i] = 'A';
            else answer[i] = 'N';
            break;
        }
    }
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "RCMA";

    init_map();
    likert_scale(survey, choices);
    make_mbti(answer);

    return answer;
}
