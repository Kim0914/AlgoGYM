#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

ll num = 0, complaint = 0, answer = 0;
vector<int> complaints;
int main() {
    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> complaint;
        complaints.push_back(complaint);
    }

    sort(complaints.begin(), complaints.end());
    for (ll i = 1; i <= num; i++)
        answer += abs(i - complaints[i - 1]);

    cout << answer;
    return 0;
}
