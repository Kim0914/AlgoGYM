#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

ll num = 0, need_weight = 0, weight = 0, cost = 0;
vector<pair<ll, ll>> meats;
bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

int main() {
    cin >> num >> need_weight;
    for (int i = 0; i < num; i++) {
        cin >> weight >> cost;
        meats.push_back({ cost, weight });
    } // 비용 순서로 정렬하도록 하자.
    sort(meats.begin(), meats.end(), cmp);
    // 싼 비용부터 무게를 더해가면 됨.

    ll weight_accum = 0, cost_to_pay = 0, answer = 0;
    for (int i = 0; i < meats.size(); i++) {
        if (weight_accum < need_weight) {
            if (i != 0 && meats[i - 1].first == meats[i].first)
                cost_to_pay += meats[i].first;
            // 같은 값이면 하나 더 사야함
            else
                cost_to_pay = meats[i].first;
        }
        else {
        // 고기 무게 합이 넘었을 때
        // 비싼 거 하나 사는 게 더 싼지 비교해야함
            if ((meats[i - 1].first != meats[i].first) && (cost_to_pay >= meats[i].first))
                cost_to_pay = meats[i].first;
            // 더 비싼 값일 때, 가격이 더 싼 경우
        }

        weight_accum += meats[i].second;
    }
    
    if (weight_accum < need_weight)
        cout << -1;
    else
        cout << cost_to_pay;
    return 0;
}
