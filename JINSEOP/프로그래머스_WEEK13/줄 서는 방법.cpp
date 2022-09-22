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
    k--; // 왜 1을 빼는가?
         // 0, 1 / 2, 3/ 4, 5 와 같이 나눴을 때 묶기 위해서.
    
    while (permutation.size() > 1) {
        factor /= n; // (n! / n) 하면 몇 칸으로 나눠지는지 나옴. 우리는 계속 이 값을 이용할 것이다.
        modular = k % factor; // 4! => 3! => 2! => 1! 으로 넘어갈 때 마다 k값이 바뀌어야 하는데, 그 Position을 정해준다.
        divisor = k / factor; // k가 몇 번째 칸에 위치하는지? 해당 값을 가져올 idx의 역할을 한다. 

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
