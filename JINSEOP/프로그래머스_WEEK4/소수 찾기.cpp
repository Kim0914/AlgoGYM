#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool visit[7] = { 0, };
vector<int> result;

void clear_vis() {
    for (int i = 0; i < 7; i++)
        visit[i] = false;
}

bool is_there(int n) {
    for (int i = 0; i < result.size(); i++) {
        if (n == result[i]) 
            return true;
    }
    return false;
}

bool is_prime(int number) {
    if (number < 2) return false;
    for (int i = 2; i <= sqrt(number); i++) // 등호 주의! 완전제곱수.
        if (number % i == 0) 
            return false;
    return true;
}

void backtrack(int start, string res, string numbers) { // 백트래킹으로 완전탐색
    visit[start] = true;

    if (is_prime(stoi(res)) == true) {
        if(!is_there(stoi(res))) 
            result.push_back(stoi(res));
    }

    if (res.size() == numbers.size()) return;

    for (int i = 0; i < numbers.size(); i++) {
        if (!visit[i]) {
            res += numbers[i];
            visit[i] = true;
            backtrack(i, res, numbers);
            res.erase(res.end() - 1);
            visit[i] = false;
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    
    for (int i = 0; i < numbers.size(); i++) {
        clear_vis();
        string temp = "";
        temp += numbers[i];
        backtrack(i, temp, numbers);
    }
    
    answer = result.size();
    return answer;
}
