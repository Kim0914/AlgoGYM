#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int num = 0, limit = 0, digit = 0;
unordered_map<int, pair<int, int>> digit_map;
vector<int> message;
bool cmp(int a, int b) {
    if (digit_map[a].first == digit_map[b].first)
        return digit_map[a].second < digit_map[b].second;

    return digit_map[a].first > digit_map[b].first;
}

int main() {
    cin >> num >> limit;
    int digit_prior_ext = 1;
    int digit_prior_in = 1;

    for (int i = 0; i < num; i++) {
        cin >> digit;
        message.push_back(digit);

        int digit_freq = digit_map[digit].first;

        if (digit_freq == 0) {
            digit_prior_in = digit_prior_ext;
            digit_prior_ext++;
        }
        else
            digit_prior_in = digit_map[digit].second;

        digit_map[digit] = { digit_freq + 1, digit_prior_in };
    }

    sort(message.begin(), message.end(), cmp);
    for (int i : message)
        cout << i << " ";

    return 0;
}
