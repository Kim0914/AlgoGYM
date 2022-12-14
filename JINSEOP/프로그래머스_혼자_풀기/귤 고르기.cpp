#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map<int, int> classifier;
vector<int> sorter;
void fill_map(vector<int> tangerine) {
    for (int t : tangerine)
        classifier[t]++;
}

void fill_vector() {
    for (auto i : classifier)
        sorter.push_back(i.second);
    sort(sorter.begin(), sorter.end(), greater<>());
}

int count_tangerine(int limit) {
    for (int i = 0; i < sorter.size(); i++) {
        limit -= sorter[i];
        if (limit <= 0)
            return i + 1;
    }
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;

    fill_map(tangerine);
    fill_vector();
    answer = count_tangerine(k);

    return answer;
}

// 가장 많은 수의 귤 종류부터 차례로 담는다.
