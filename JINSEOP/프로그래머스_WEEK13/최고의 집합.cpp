#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s)
{
    vector<int> answer;

    if (n > s) {
        answer.push_back(-1);
        return answer;
    }

    for(int i = 1; i <= n; i++)
        answer.push_back(s / n);
    
    for(int i = 1; i <= s % n; i++)
        answer[n - i]++;

    return answer;
}

// 최대한 균등할 때, 곱이 최대가 된다!
// 문제가 어이가 없네..
