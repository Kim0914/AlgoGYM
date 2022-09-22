#include <iostream>
#include <vector>
using namespace std;

long long DP[21];
vector<int> permutation;
void init_factorial(int n) {
    DP[0] = 1;
    for (int i = 1; i <= n; i++)
        DP[i] = i * DP[i - 1];
}

void make_vector(int n) {
    for (int i = 1; i <= n; i++)
        permutation.push_back(i);
}

void calculate_permutation(int n, long long k, vector<int>& answer) {
    long long factor = DP[n];
    long long modular = 0, divisor = 0;
    k--;

    while (permutation.size() > 1) {
        factor /= n;
        modular = k % factor;
        divisor = k / factor;

        answer.push_back(permutation[divisor]);
        permutation.erase(permutation.begin() + divisor);
        
        k = modular;
        n--;
    }

    answer.push_back(permutation[0]);
}

vector<int> solution(int n, long long k) {
    vector<int> answer;

    make_vector(n);
    init_factorial(n);
    calculate_permutation(n, k, answer);

    return answer;
}
