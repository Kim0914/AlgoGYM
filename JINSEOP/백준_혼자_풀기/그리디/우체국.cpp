#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

int num = 0;
ll village = 0, population = 0, pop_sum = 0, answer = 20000000000;
vector<pair<ll, ll>> villages;
vector<ll> piled_sum;
int main() {
    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> village >> population;
        villages.push_back({ village, population });
    // 마을을 순서대로 정렬하기 위해 village를 앞으로 둔다.
    }

    sort(villages.begin(), villages.end());
    // 마을을 위치 순서대로 오름차순 정렬

    piled_sum.push_back(villages[0].second);
    for (int i = 1; i < num; i++)
        piled_sum.push_back(piled_sum[i-1] + villages[i].second);

    ll left = 0, right = num - 1;
    while (left <= right) {
        ll mid = (left + right) / 2;

    // 어떤 기준으로 mid를 옮길 것인가?
        ll partial_left_sum = piled_sum[mid];
        ll partial_right_sum = piled_sum[num - 1] - piled_sum[mid];

        if (partial_left_sum >= partial_right_sum) {
            right = mid - 1;
            answer = min(answer, villages[mid].first);
        }
        else
            left = mid + 1;
    }

    cout << answer;
    return 0;
}
