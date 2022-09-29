#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calculate_min_sum(vector<int> A, vector<int> B) {
    int sum = 0;

    for (int i = 0; i < A.size(); i++)
        sum += (A[i] * B[i]);

    return sum;
}

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<>());
    answer = calculate_min_sum(A, B);

    return answer;
}
