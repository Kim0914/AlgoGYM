#include <iostream>
#include <string>
#include <vector>
using namespace std;

void make_answer(vector<long long>& answer, int x, int n) {
    for (int i = 1; i <= n; i++)
        answer.push_back(x * i);
}

vector<long long> solution(int x, int n) {
    vector<long long> answer;

    make_answer(answer, x, n);
    return answer;
}
