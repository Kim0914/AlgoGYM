#include <string>
#include <vector>
using namespace std;

void get_divisors(vector<int> &divisors) {
    for (int i = 1; i < divisors.size(); i++) {
        for (int j = i; j < divisors.size(); j += i)
            divisors[j]++;
    }
}

void calculate_weight(int number, int limit, int power, int &answer, vector<int> divisors) {
    for (int i = 1; i <= number; i++) {
        if (divisors[i] > limit)
            answer += power;
        else
            answer += divisors[i];
    }
}

int solution(int number, int limit, int power) {
    int answer = 0;
    vector<int> divisors(number + 1, 0);

    get_divisors(divisors);
    calculate_weight(number, limit, power, answer, divisors);

    return answer;
}
