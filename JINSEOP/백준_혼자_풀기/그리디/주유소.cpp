#include <iostream>
using namespace std;
#define ll long long

ll num = 0;
ll cities[100000], dist[100000], answer = 0;
int main() {
    cin >> num;
    for (int i = 0; i < num - 1; i++)
        cin >> dist[i];
    for (int i = 0; i < num; i++)
        cin >> cities[i];

    ll gasoline = cities[0];
    answer += (gasoline * dist[0]);
    // 첫 도시까지는 무조건 넣어야 함
    for (int i = 1; i < num - 1; i++) {
        if (gasoline > cities[i])
            gasoline = cities[i];
        // 더 싸게 기름을 넣을 수 있으면 바꿈
        answer += (gasoline * dist[i]);
    }

    cout << answer;
    return 0;
}
