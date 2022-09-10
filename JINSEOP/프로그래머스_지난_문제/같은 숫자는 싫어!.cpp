#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

stack<int> duplication_remover;
void duplication_remove(vector<int> arr, vector<int>& answer) {
    duplication_remover.push(arr[0]);

    for (int i = 1; i < arr.size(); i++) {
        if(duplication_remover.top() != arr[i])
            duplication_remover.push(arr[i]);
    }

    while (!duplication_remover.empty()) {
        answer.push_back(duplication_remover.top());
        duplication_remover.pop();
    }

    reverse(answer.begin(), answer.end());
}

vector<int> solution(vector<int> arr){
    vector<int> answer;

    duplication_remove(arr, answer);
    return answer;
}
