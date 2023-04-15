#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(vector<int> a, vector<int> b) {
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0, e = 0;

    sort(targets.begin(), targets.end(), cmp);

    for (auto vec : targets) {
        if (vec[0] >= e) {
            answer++;
            e = vec[1];
        }
    }

    return answer;
}
