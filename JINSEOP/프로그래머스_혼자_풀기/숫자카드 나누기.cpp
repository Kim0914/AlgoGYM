#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int get_gcd(vector<int> arr) {
    int min_v = *min_element(arr.begin(), arr.end());
    bool is_divide = true;

    while (min_v != 1) {
        is_divide = true;
        
        for (int i = 0; i < arr.size(); i++)
            if ((arr[i] % min_v) != 0) {
                is_divide = false;
                min_v -= 1;
                break;
            }

        if (is_divide)
            return min_v;
    }

    return 0;
}

bool validate(int key, vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % key == 0)
            return false;
    }

    return true;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int a_gcd = 0, b_gcd = 0;

    a_gcd = get_gcd(arrayA);
    if (a_gcd != 0) {
        if (validate(a_gcd, arrayB))
            answer = a_gcd;
    }

    b_gcd = get_gcd(arrayB);
    if (b_gcd != 0) {
        if (validate(b_gcd, arrayA))
            answer = b_gcd > a_gcd ? b_gcd : a_gcd;
    }

    return answer;
}
