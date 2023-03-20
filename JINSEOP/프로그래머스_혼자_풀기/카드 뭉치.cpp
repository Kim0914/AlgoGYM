#include <string>
#include <vector>
#include <queue>
using namespace std;

queue<string> word_q1;
queue<string> word_q2;
void fill_queue(vector<string> cards1, vector<string> cards2) {
    for (string s : cards1)
        word_q1.push(s);
    for (string s : cards2)
        word_q2.push(s);
}

string validate_card(vector<string> goal) {
    for (string s : goal) {
        if (!word_q1.empty() && s == word_q1.front())
            word_q1.pop();
        else if (!word_q2.empty() && s == word_q2.front())
            word_q2.pop();
        else
            return "No";
    }

    return "Yes";
}

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";

    fill_queue(cards1, cards2);
    answer = validate_card(goal);

    return answer;
}
