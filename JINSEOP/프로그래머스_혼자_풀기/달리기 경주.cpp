#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<string, int> rank_map;
void fill_map(vector<string> players) {
    for (int i = 0; i < players.size(); i++)
        rank_map[players[i]] = i;
}

void calculate_rank(vector<string>& players, vector<string> callings) {
    for (string s : callings) {
        swap(players[rank_map[s]], players[rank_map[s]-1]);
        rank_map[players[rank_map[s]]]++; // 뒤로 밀림
        rank_map[s]--; // 추월
    }
}

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;

    fill_map(players);
    calculate_rank(players, callings);
    answer = players;

    return answer;
}
