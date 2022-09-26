#include <string>
#include <vector>
using namespace std;

int calculate_gcd(int n, int m, vector<int>& answer) {
    if (m == 0){
        answer.push_back(n);
        return n;
    }
    else
        return calculate_gcd(m, n % m, answer);
}

void calculate_lcm(int n, int m, vector<int>& answer) {
    answer.push_back((n * m) / answer[0]);
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    calculate_gcd(n, m, answer);
    calculate_lcm(n, m, answer);

    return answer;
}
