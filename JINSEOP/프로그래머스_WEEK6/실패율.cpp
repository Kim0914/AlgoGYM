#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct info {
    float data;
    int _id;
};

map<int, float> counter;
vector<info> stage_list;

bool cmp(info& a, info& b) {
    if (a.data == b.data) return a._id < b._id;
    return a.data > b.data;
}

void init_info(int N) {
    for (int i = 1; i < N + 1; i++) {
        info temp;
        temp._id = i; temp.data = 0;
        stage_list.push_back(temp);
    }

}

void make_map(int N, vector<int> stages) {
    for (int i = 1; i < N + 1; i++)
        counter[i] = 0;

    for (int i = 0; i < stages.size(); i++)
        counter[stages[i]]++;
}

void calc_rate(float challenger, int N) {
    for (int i = 1; i < N + 1; i++) {
        if (challenger == 0) {
            stage_list[i - 1].data = 0;
            continue;
        }
        float ratio = counter[i] / challenger;
        stage_list[i - 1].data = ratio;
        challenger -= counter[i];
    }
}

void make_answer(vector<int>& answer) {
    for (int i = 0; i < stage_list.size(); i++)
        answer.push_back(stage_list[i]._id);

}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    float challenger = stages.size();

    init_info(N);
    make_map(N, stages);
    calc_rate(challenger, N);

    sort(stage_list.begin(), stage_list.end(), cmp);
    make_answer(answer);

    return answer;
}
