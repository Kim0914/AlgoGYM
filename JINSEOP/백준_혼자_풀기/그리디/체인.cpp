#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int num = 0, chain = 0;
vector<int> chains;
int main() {
    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> chain;
        chains.push_back(chain);
    }

    sort(chains.begin(), chains.end());

    // 가장 짧은 체인을 모두 해체해서 연결할 것인가?
    // 아니면 끝부분끼리 연결할 것인가?
    // 연결 부위끼리 연결하는 경우는, n - 1

    int chain_num = num - 1, answer = 0;
    // 연결해야 할 연결 부분의 수
    for (int i = 0; i < chains.size(); i++) {
        if (chain_num >= chains[i]) {
            // 연결해야할 부분이 가장 짧은 체인보다 많으면
            // 모두 사용할 수 있음
            chain_num -= 1; // 가장 짧은 고리 제외
            chain_num -= chains[i];
            answer += chains[i];
        }
        else {
            answer += chain_num;
            chain_num = 0;
        }

        if (chain_num <= 0)
            break;
    }

    cout << answer;
    return 0;
}
