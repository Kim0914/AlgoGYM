#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    answer.push_back(x);
    int temp = x;
    for(int i = 0; i < n-1; i++){
        temp += x;
        answer.push_back(temp);
    }
    return answer;
}
