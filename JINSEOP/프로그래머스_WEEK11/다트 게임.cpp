#include <vector>
#include <string>
using namespace std;

vector<int> score_list;
vector<char> bonus_list;
vector<pair<char, int>> option_list;

int str_to_int(string str) {
    if (str == "10") return 10;
    else return stoi(str);
}

void parse_dart(string dartResult) {
    string num_temp = "";

    for (auto c : dartResult) {
        if (c >= '0' && c <= '9')
            num_temp += c;
        if (c == 'S' || c == 'D' || c == 'T') {
            score_list.push_back(str_to_int(num_temp));  
            num_temp = "";
            bonus_list.push_back(c);
        }
        if (c == '*' || c == '#') option_list.push_back({c, bonus_list.size()-1});
    }
}

int calc_score() {
    int sum = 0;

    for (int i = 0; i < score_list.size(); i++) {
        switch (bonus_list[i])
        {
        case 'S':
            break;
        case 'D':
            score_list[i] = (score_list[i] * score_list[i]);
            break;
        case 'T':
            score_list[i] = (score_list[i] * score_list[i] * score_list[i]);
            break;
        }
    }

    for (int i = 0; i < option_list.size(); i++) {
        switch (option_list[i].first)
        {
        case '*':
            if (option_list[i].second == 0)
                score_list[option_list[i].second] *= 2;
            else {
                score_list[option_list[i].second - 1] *= 2;
                score_list[option_list[i].second] *= 2;
            }
            break;
        case '#':
            score_list[option_list[i].second] *= -1;
            break;
        }
    }

    for (int i : score_list) sum += i;

    return sum;
}

int solution(string dartResult) {
    int answer = 0;

    parse_dart(dartResult);
    answer = calc_score();
    return answer;
}
