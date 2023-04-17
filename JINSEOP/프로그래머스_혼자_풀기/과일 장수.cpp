#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.begin(), score.end(), greater<>());
    
    for(int i = m; i <= score.size(); i += m)
        answer += score[i-1] * m;
    
    return answer;
}
