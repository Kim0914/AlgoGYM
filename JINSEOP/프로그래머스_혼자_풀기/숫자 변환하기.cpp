#include <string>
#include <vector>
#include <iostream>
using namespace std;
#define BIGINT 9999999

int res = BIGINT;
void recur(int x, int y, int n, int depth) {
    if (x == y) {
        if (res > depth)
            res = depth;

        return;
    }
    
    if (x > y) return;

    recur(x + n, y, n, depth + 1);
    recur(x * 2, y, n, depth + 1);
    recur(x * 3, y, n, depth + 1);
}

int solution(int x, int y, int n) {
    int answer = 0;
    recur(x, y, n, 0);

    if (res == BIGINT)
        answer = -1;
    else
        answer = res;

    return answer;
}
