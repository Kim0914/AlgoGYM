#include <string>
#include <vector>
using namespace std;

int res = 0, sum = 0;
string temp = "";
void backtrack(int depth, int idx, vector<int> number, vector<bool>& visit) {
    if (depth == 3) {
        if(sum == 0) res++;
        return;
    }

    for (int i = idx; i < number.size(); i++) {
        if (!visit[i]) {
            visit[i] = true;
            sum += number[i];
            backtrack(depth + 1, i,  number, visit);
            visit[i] = false;
            sum -= number[i];
        }
    }
}

int solution(vector<int> number) {
    int answer = 0;
    vector<bool> visit(number.size(), false);

    backtrack(0, 0, number, visit);
    answer = res;
    return answer;
}
