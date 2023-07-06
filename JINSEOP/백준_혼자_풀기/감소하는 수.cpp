#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> decreases;
vector<long long> decrease_sequence;
int main() {
    int num = 0;
    string prefix = "", temp = "";

    cin >> num;
    if (num > 1022)
        cout << -1; // 감소수는 0부터 9876543210까지 1023개가 존재한다.
    else {
        decreases.push_back("0");

        for (int i = 1; i < 10; i++) { // 감소수 배열을 만듬
            prefix = to_string(i);
            decreases.push_back(prefix); // 이미 있는 수의 앞에 접두사로 1, 2..., 9를 붙임
            int curr_size = decreases.size();

            for (int j = 0; j < curr_size; j++) {
                if (prefix == decreases[j])
                    continue;
                temp = prefix + decreases[j];
                decreases.push_back(temp);
            }
        }

        for (auto i : decreases) // 정렬을 위해 형 변환
            decrease_sequence.push_back(stoll(i));
        sort(decrease_sequence.begin(), decrease_sequence.end()); // 답 출력을 위해 정렬

        cout << decrease_sequence[num];
    }
}
