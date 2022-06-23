#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int t_case = 0; t_case < commands.size(); t_case++) {
        priority_queue<int, vector<int>, greater<int>> max_q;
        int cnt = commands[t_case][2];
        for (int i = commands[t_case][0] - 1; i < commands[t_case][1]; i++)
            max_q.push(array[i]);
        while (cnt > 1) {
            max_q.pop();
            cnt--;
        }
        answer.push_back(max_q.top());
    }

    return answer;
}
