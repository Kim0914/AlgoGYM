#include <string>
#include <vector>

using namespace std;

vector<int> trinomial;
void dec_to_tri(int n) {
    while (n != 0) {
        trinomial.push_back(n % 3);
        n /= 3;
    }
}

int tri_to_dec() {
    int res = 0, multi = 1;
    for (int i = trinomial.size() - 1; i >= 0; i--) {
        res += trinomial[i] * multi;
        multi *= 3;
    }

    return res;
}

int solution(int n) {
    int answer = 0;

    dec_to_tri(n);
    answer = tri_to_dec();

    return answer;
}
