#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

struct cmp {
    bool operator()(pair<vector<string>, int> &a, pair<vector<string>, int> &b) {
        return a.second < b.second;
    }
};

priority_queue<pair<vector<string>, int>, vector<pair<vector<string>, int>>, cmp> mineral_q;
void fill_queue(vector<int> picks, vector<string> minerals) {
    int mineral_size = minerals.size();
    int max_mineral = (picks[0] + picks[1] + picks[2]) * 5;

    for (int i = 0; i < min(mineral_size, max_mineral); i += 5) {
        vector<string> temp_vec;
        int fatigue = 0;
        for (int j = i; j < i + 5 && j < mineral_size; j++) {
            if (minerals[j] == "diamond") fatigue += 25;
            if (minerals[j] == "iron") fatigue += 5;
            if (minerals[j] == "stone") fatigue += 1;

            temp_vec.push_back(minerals[j]);
        }

        mineral_q.push({ temp_vec, fatigue });
    }
}

void calculate_fatigue(vector<int> &picks, int &answer) {
    while (!mineral_q.empty()) {
        for (auto i : mineral_q.top().first)
            cout << i << " ";
        cout << mineral_q.top().second << endl;

        if (picks[0] != 0) {
            answer += 5;
            picks[0] -= 1;
        }
        else if (picks[1] != 0) {
            for (int i = 0; i < mineral_q.top().first.size(); i++) {
                if (mineral_q.top().first[i] == "diamond")
                    answer += 5;
                else
                    answer += 1;
            }

            picks[1] -= 1;
        }
        else {
            for (int i = 0; i < mineral_q.top().first.size(); i++) {
                if (mineral_q.top().first[i] == "diamond")
                    answer += 25;
                else if (mineral_q.top().first[i] == "iron")
                    answer += 5;
                else
                    answer += 1;
            }

            picks[2] -= 1;
        }

        mineral_q.pop();
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    
    fill_queue(picks, minerals);
    calculate_fatigue(picks, answer);
    
    return answer;
}

int main() {
    vector<int> picks = { 0, 0, 1 };
    vector<string> minerals = { "iron" };
    cout << solution(picks, minerals);
    return 0;
}
