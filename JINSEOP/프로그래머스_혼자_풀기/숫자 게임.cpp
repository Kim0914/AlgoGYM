#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(B.begin(), B.end());

    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B.size(); j++) {
            if (A[i] < B[j]) {
                B.erase(B.begin() + j);
                answer++;
                break;
            }
        }
    }

    return answer;
}
