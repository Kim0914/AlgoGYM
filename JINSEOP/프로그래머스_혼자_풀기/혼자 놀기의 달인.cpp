#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> count_list;
int cnt = 0;

void make_group(int idx, vector<int> cards, vector<bool>& visit) {
    visit[idx] = true;
    cnt += 1;

    if (!visit[(cards[idx] - 1)])
        make_group((cards[idx] - 1), cards, visit);
    else
        return;
}

void dfs(vector<int> cards, vector<bool>& visit) {
    for (int i = 0; i < cards.size(); i++)
        if (!visit[i]) {
            cnt = 0;
            make_group(i, cards, visit);
            count_list.push_back(cnt);
        }
}

int solution(vector<int> cards) {
    int answer = 0;
    vector<bool> visit(cards.size(), 0);

    dfs(cards, visit);
    
    if (count_list.size() == 1) 
        return 0;
    else {
        sort(count_list.begin(), count_list.end(), greater<>());
        answer = count_list[0] * count_list[1];
    }

    return answer;
}
