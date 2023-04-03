#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> score_library;
void fill_library(vector<string> name, vector<int> yearning) {
    for (int i = 0; i < name.size(); i++)
        score_library[name[i]] = yearning[i];
}

void calculate_score(vector<vector<string>> photo, vector<int> &answer) {
    for (auto vec : photo) {
        int sum = 0;

        for (string s : vec)
            sum += score_library[s];

        answer.push_back(sum);
    }
}

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;

    fill_library(name, yearning);
    calculate_score(photo, answer);

    return answer;
}
