#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int, int> rank_caculator;

void init_calculator(vector<int> lottos, vector<int> win_nums) {
    for (int i = 0; i < 6; i++) {
        rank_caculator[lottos[i]]++;
        rank_caculator[win_nums[i]]++;
    }
}

void calc_rank(vector<int>& answer) {
    int rank = 7, zero_num = 0;

    for (auto comp : rank_caculator) {
        if (comp.first != 0 && comp.second > 1)
            rank--;
        if (comp.first == 0)
            zero_num = comp.second;
    }

    answer.push_back(((rank - zero_num) > 6 ? 6 : (rank - zero_num)));
    answer.push_back(rank > 6 ? 6 : rank);
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;

    init_calculator(lottos, win_nums);
    calc_rank(answer);

    return answer;
}
