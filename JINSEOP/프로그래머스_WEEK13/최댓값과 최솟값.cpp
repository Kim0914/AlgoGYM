#include <string>
#include <vector>
#include <set>
using namespace std;

set<int> heap;
void parse_sequence(string s) {
    string temp = "";

    for (char c : s) {
        if (c == ' ') {
            heap.insert(stoi(temp));
            temp = "";
            continue;
        }

        temp += c;
    }

    heap.insert(stoi(temp));
}

void make_answer(string& answer) {
    answer += to_string( * heap.begin());
    answer += " ";
    answer += to_string( * (--heap.end()));
}

string solution(string s) {
    string answer = "";

    parse_sequence(s);
    make_answer(answer);

    return answer;
}
