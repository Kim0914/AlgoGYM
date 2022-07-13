#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(), d.end());
    for(int money: d){
        if(budget<money) break;
        answer++;
        budget-=money;
    }
    return answer;
}