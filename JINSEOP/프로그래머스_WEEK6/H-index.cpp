#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

map<int, int, greater<int>> info;
void init_map(vector<int> citations){
    int max_v = *max_element(citations.begin(), citations.end());

    for (int i = 0; i<=max_v; i++)
        info[i] = 0;
}

void fill_map(vector<int> citations) {
    for (int key = 0; key < info.size(); key++) {
        for (int val = 0; val < citations.size(); val++) {
            if (key <= citations[val])
                info[key]++;
        }
    }
}

int count_map() {
    for (auto i : info) {
        for (int cnt = 0; cnt <= i.second; cnt++) {
            if (i.first == cnt) return i.first;
        }
    }
}

int solution(vector<int> citations) {
    int answer = 0;

    sort(citations.begin(), citations.end());

    init_map(citations);
    fill_map(citations);

    answer = count_map();
    return answer;
}
