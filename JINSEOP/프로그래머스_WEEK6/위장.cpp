#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

unordered_map<string, int> table;
int cnt = 1, sum = 0;

void make_table(vector<vector<string>> clothes) {
    for (auto i : clothes)
        table[i[1]]++;
}

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    make_table(clothes);
    for (auto i : table) {
        answer *= i.second + 1;
    }

    return answer - 1;
}
