using namespace std;

long long solution(int price, int money, int count)
{
    int answer = -1;
    long long cost = 0;
    for(int i = 1; i <= count;i++){
        cost += i;
    }
    cost *= price;
    if(cost <= money) return 0;
    else return cost - money;
}
