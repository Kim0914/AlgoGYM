#include <string>
#include <vector>
#include <cmath>
using namespace std;

bool is_prime(long long n) {
    if (n < 2) return false;

    for (long long i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;

    return true;
}

string convert_k_ary(int n, int k) {
    string k_ary = "";

    while (n > 0) {
        char part = (n % k) + '0';
        k_ary = part + k_ary;
        n /= k;
    }

    return k_ary;
}

int match_condition(string k_ary) {
    int cnt = 0;
    string temp = "";

    for (int i = 0; i < k_ary.size(); i++) {
        if (k_ary[i] == '0') {
            if (temp == "") continue;
            if (is_prime(stoll(temp)))
                cnt++;
            temp = "";
        }
        else temp += k_ary[i];
    }
    
    if (temp == "") return cnt;
    
    if (is_prime(stoll(temp))) cnt++;
    return cnt;
}

int solution(int n, int k) {
    int answer = -1;

    answer = match_condition(convert_k_ary(n, k));
    return answer;
}

// stoll(temp) 함수의 존재를 잊지말자!
