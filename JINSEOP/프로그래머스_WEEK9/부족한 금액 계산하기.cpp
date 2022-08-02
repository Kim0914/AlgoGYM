using namespace std;

long long DP[2501];

void fill_DP(int price, int count) {
    DP[1] = price;
    for (long long i = 2; i <= count; i++) {
        DP[i] = DP[i - 1] + (price * i);
    }
}

long long solution(int price, int money, int count){
    long long answer = 0;

    fill_DP(price, count);
    if (DP[count] - money <= 0) return answer;
    else answer = DP[count] - money;

    return answer;
}
