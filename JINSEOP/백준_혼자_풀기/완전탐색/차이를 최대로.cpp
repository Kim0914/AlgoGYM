#include <iostream>
#include <vector>
using namespace std;

int num = 0, answer = 0;
int seq[8];
bool visit[8];
vector<int> permutation;
int calculate_diff() {
    int diff_sum = 0;

    for (int i = 0; i < permutation.size() - 1; i++)
        diff_sum += abs(permutation[i] - permutation[i + 1]);

    return diff_sum;
}

void make_permutation(int depth, int idx) {
    if (depth == num) {
        answer = max(answer, calculate_diff());
        return;
    }

    for (int i = 0; i < num; i++) {
        if (!visit[i]) {
            visit[i] = true;
            permutation.push_back(seq[i]);
            make_permutation(depth + 1, i);
            visit[i] = false;
            permutation.pop_back();
        }
    }
}

int main(){
    cin >> num;
    for (int i = 0; i < num; i++)
        cin >> seq[i];

    for (int i = 0; i < num; i++) {
        visit[i] = true;
        permutation.push_back(seq[i]);
        make_permutation(1, i);
        visit[i] = false;
        permutation.pop_back();
    }

    cout << answer;
    return 0;
}
