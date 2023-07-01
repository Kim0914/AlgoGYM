#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

unordered_map<int, int> appliance_map;
unordered_map<int, int> prior_map;
vector<int> appliance_v;
vector<int> socket;
int main() {
    int hole = 0, freq = 0, used = 0;
    int latest_idx = 0, latest = 0, cnt = 0;

    cin >> hole >> freq;
    for (int i = 0; i < freq; i++) {
        cin >> used;
        if (prior_map[used] == 0)
            prior_map[used] = i + 1;
        appliance_v.push_back(used);
    }

    for (int i = 0; i < appliance_v.size(); i++) {
        if (socket.size() < hole) { // 빈 자리가 있을 때
            if (appliance_map[appliance_v[i]] == 0) { // 사용 중이 아닌 기구라면?
                socket.push_back(appliance_v[i]); // 투입
                appliance_map[appliance_v[i]] = 1; // 사용 중 표시

                for (int j = i + 1; j < appliance_v.size(); j++) { // 추후 등장할 인덱스 갱신
                    if (appliance_v[i] == appliance_v[j]) {
                        prior_map[appliance_v[i]] = j + 1;
                        break;
                    }
                }
            }
            else {
                for (int j = i + 1; j < appliance_v.size(); j++) { // 추후 등장할 인덱스 갱신
                    if (appliance_v[i] == appliance_v[j]) {
                        prior_map[appliance_v[i]] = j + 1;
                        break;
                    }
                }
            } // 사용 중이라면 인덱스만 갱신
        }
        else { // 빈 자리가 없을 때
            if (appliance_map[appliance_v[i]] == 0) { // 사용 중이 아닌 기구라면?
                for (int j = 0; j < socket.size(); j++) {
                    if (latest < prior_map[socket[j]]) {
                        latest = prior_map[socket[j]];
                        latest_idx = j;
                    }
                } // 추후에 가장 늦게 등장할 기구 뽑아내면서, 빈 자리 표시

                appliance_map[socket[latest_idx]] = 0;
                socket[latest_idx] = appliance_v[i];
                appliance_map[appliance_v[i]] = 1;
                // 현재 기구 투입 후 사용 중 표시

                for (int j = i + 1; j < appliance_v.size(); j++) { // 추후 등장할 인덱스 갱신
                    if (appliance_v[i] == appliance_v[j]) {
                        prior_map[appliance_v[i]] = j + 1;
                        break;
                    }
                }
                cnt++;

                // 기구를 뽑았으니, count 증가
            }
            else {
                for (int j = i + 1; j < appliance_v.size(); j++) { // 추후 등장할 인덱스 갱신
                    if (appliance_v[i] == appliance_v[j]) {
                        prior_map[appliance_v[i]] = j + 1;
                        break;
                    }
                }
            } // 사용 중이라면 인덱스만 갱신
        }
    }

    cout << cnt;

    return 0;
}
