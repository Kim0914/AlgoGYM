#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sensor_num = 0, centre_num = 0, sensor_pos = 0, answer = 0;
// 최대 centre_num개 세웠을 때 수신 가능한 거리의 합
vector<int> coord_list;
vector<int> dist_list;
int main() {
    cin >> sensor_num >> centre_num;
    for (int i = 0; i < sensor_num; i++) {
        cin >> sensor_pos;
        coord_list.push_back(sensor_pos);
    }
    // centre_num개의 구간으로 분할해야 한다.
    // 하지만, 각 구간의 길이의 합이 최소여야 한다.
    
    sort(coord_list.begin(), coord_list.end());
    // 우선 각 구간의 길이를 저장하기 위해, 정렬한다.
    for (int i = 1; i < coord_list.size(); i++)
        dist_list.push_back(coord_list[i] - coord_list[i - 1]);
    // 앞에서 뒤로 모든 구간의 길이가 저장된다.

    sort(dist_list.begin(), dist_list.end());
    // 구간들 또한 오름차순 정렬을 해야 한다.
    for (int i = 0; i < sensor_num - centre_num; i++)
        answer += dist_list[i];
    // 이제 정렬한 구간을 앞에서 부터, (센서 수 - 기지국 수) 만큼 선택한다.
    // 왜? 기지국 수가 하나 늘어날 때마다, 가장 먼 구간을 떼고 배분하면 된다.
  
    cout << answer;
    return 0;
}
