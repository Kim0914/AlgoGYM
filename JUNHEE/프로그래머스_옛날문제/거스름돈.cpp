#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;
    vector<int> list(n + 1, 0);
    list[0] = 1;
    for(int i = 0; i < money.size(); i++){
        for(int j = money[i]; j < list.size(); j++){
            list[j] = list[j] + list[j - money[i]];
        }
    }
    answer = list.back();
    return answer;
}
