#include <string>
#include <vector>
using namespace std;

int calculate_partition(int x) {
    int sum = 0;

    while (x != 0) {
        sum = sum + (x - ((x / 10) * 10));
        x /= 10;
    }

    return sum;
}

bool check_harshard(int x, int sum) {
    if (x % sum == 0) return true;
    else return false;
}

bool solution(int x) {
    bool answer = true;
    
    int check_sum = calculate_partition(x);
    answer = check_harshard(x, check_sum);

    return answer;
}
