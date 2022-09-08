#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool validate(vector<int> arr, int lcm) {
    for (int i : arr)
        if (lcm % i != 0) return false;

    return true;
}

int find_lcm(vector<int> arr) {
    int max_v = *max_element(arr.begin(), arr.end());
    int lcm = max_v, mul = 2;

    while (!validate(arr, lcm))
        lcm = max_v * (mul++);

    return lcm;
}

int solution(vector<int> arr) {
    int answer = 0;

    answer = find_lcm(arr);
    return answer;
}
