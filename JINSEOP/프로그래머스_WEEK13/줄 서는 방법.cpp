#include <iostream>
#include <vector>
using namespace std;

string permutation = "";
long long cnt = 0;
bool is_end = false;
void backtrack(long long k, vector<int>& visit) {
    if (permutation.size() == visit.size()) {
        cnt++;
        if (cnt == k)
            is_end = true;
        return;
    }

    for (int i = 0; i < visit.size(); i++) {
        if (!visit[i]) {
            visit[i] = true;
            permutation += ((i + 1) + '0');
            backtrack(k, visit);
            if (is_end) return;
            visit[i] = false;
            permutation.pop_back();
        }
    }
}

void string_vectorize(vector<int>& answer) {
    for (char c : permutation)
        answer.push_back(c - '0');
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> visit(n, 0);
    
    backtrack(k, visit);
    string_vectorize(answer);

    return answer;
}

int main() {
    cout << solution(3, 5);
	return 0;
}
