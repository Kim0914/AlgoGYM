#include <string>
#include <vector>
using namespace std;
#define BIGINT 9999999

int DP[1000001];
void fill_DP(int x, int y, int n) {
    for (int i = x + 1; i < y + 1; i++) {
        int key_a = BIGINT, key_b = BIGINT, key_c = BIGINT, kind = 0;

        if ((i % 2 == 0) && (i / 2 >= x))
            key_a = DP[i / 2];
        if ((i % 3 == 0) && (i / 3 >= x))
            key_b = DP[i / 3];
        if ((i - n) >= x)
            key_c = DP[i - n];

        kind = min(min(key_a, key_b), key_c);

        if (kind == BIGINT)
            DP[i] = BIGINT;
        else
            DP[i] = kind + 1;
    }
}

int solution(int x, int y, int n) {
    fill_DP(x, y, n);

    if (DP[y] == BIGINT)
        return -1;
    else
        return DP[y];
}
