#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
using namespace std;

unordered_map<string, int> hash_map;
unordered_map<string, int> hash_num_map;
map<int, string, greater<>> inverse_map;
vector<pair<string, pair<int, int>>> info_vec;
bool cmp(pair<string, pair<int, int>> a, pair<string, pair<int, int>> b) {
    if (a.second.second == b.second.second) return a.second.first < b.second.first;
    return a.second.second > b.second.second;
}
void init_map(vector<string> genres, vector<int> plays) {
    for (int i = 0; i < genres.size(); i++) {
        hash_map[genres[i]] += plays[i];
        hash_num_map[genres[i]]++;
    }

    for (auto i : hash_map)
        inverse_map[i.second] = i.first;
}

void init_vec(vector<string> genres, vector<int> plays) {
    for (int i = 0; i < genres.size(); i++)
        info_vec.push_back({ genres[i], {i, plays[i]} });

    sort(info_vec.begin(), info_vec.end(), cmp);
}

void select_bestseller(vector<int>& answer) {
    for (auto i : inverse_map) {
        int cnt = 0;
        for (int k = 0; k < info_vec.size(); k++) {
            if (info_vec[k].first == i.second) {
                if (hash_num_map[i.second] == 1) {
                    answer.push_back(info_vec[k].second.first);
                    break;
                }
                answer.push_back(info_vec[k].second.first);
                cnt++;
            }
            if (cnt == 2) break;
        }
    }
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    init_map(genres, plays);
    init_vec(genres, plays);
    select_bestseller(answer);

    return answer;
}
