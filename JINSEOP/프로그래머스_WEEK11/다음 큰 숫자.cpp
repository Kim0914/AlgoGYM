#include <string>
#include <vector>
using namespace std;

string dec_to_bin(int n) {
    string binary = "";

    while (n != 0) {
        char bin = n % 2 + '0';
        binary = bin + binary;
        n /= 2;
    }

    return binary;
}

int count_one(string s) {
    int cnt = 0;

    for (auto c : s)
        if (c == '1') cnt++;

    return cnt;
}

bool validate(string cmp, int std_cnt) {
    if (count_one(cmp) == std_cnt)
        return true;
    else return false;
}

int solution(int n) {
    int answer = 0;
    string std = "", cmp = "";

    std = dec_to_bin(n);
    int std_cnt = count_one(std);

    while (true) {
        n++;
        cmp = dec_to_bin(n);
        if (validate(cmp, std_cnt)) break;
    }

    answer = n;
    return answer;
}
