#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int supo[3] = {0,};
int one[5] = {1,2,3,4,5};
int two[8] = {2,1,2,3,2,4,2,5};
int three[10] = {3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int max_scr = 0;

    for (int i = 0; i < answers.size(); i++) {
        if (one[i % 5] == answers[i]) supo[0]++;
        if (two[i % 8] == answers[i]) supo[1]++;
        if (three[i % 10] == answers[i]) supo[2]++;
    }

    max_scr = *max_element(supo, supo+3);
    for (int i = 0; i < 3; i++) 
        if (supo[i] == max_scr) answer.push_back(i+1);

    return answer;
}
