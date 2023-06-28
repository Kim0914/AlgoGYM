#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int max_v = -1000000000, min_v = 1000000000;
unordered_map<string, int> op_map;
void calc_sum(vector<int> sequence, int curr, int sum, int add, int sub, int mul, int div) {
    if (curr >= sequence.size()) {
        if (sum > max_v)
            max_v = sum;
        if (sum < min_v)
            min_v = sum;

        return;
    }

    if (add > 0)
        calc_sum(sequence, curr + 1, sum + sequence[curr], add - 1, sub, mul, div);
    if (sub > 0)
        calc_sum(sequence, curr + 1, sum - sequence[curr], add, sub - 1, mul, div);
    if (mul > 0)
        calc_sum(sequence, curr + 1, sum * sequence[curr], add, sub, mul - 1, div);
    if (div > 0)
        calc_sum(sequence, curr + 1, sum / sequence[curr], add, sub, mul, div - 1);
}

int main() {
    int n = 0, num = 0;
    vector<int> sequence;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        sequence.push_back(num);
    }
    cin >> op_map["+"] >> op_map["-"] >> op_map["*"] >> op_map["/"];

    calc_sum(sequence, 1, sequence[0], op_map["+"], op_map["-"], op_map["*"], op_map["/"]);

    cout << max_v << "\n";
    cout << min_v;
    return 0;
}
