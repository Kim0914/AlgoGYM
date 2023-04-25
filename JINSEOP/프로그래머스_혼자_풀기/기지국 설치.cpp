#include <iostream>
#include <vector>
using namespace std;

int res = 0;
void set_station(int start, int end, int range) {
    int total_dist = end - start + 1;
    
    if(total_dist <= 0) return;
    if (total_dist % range == 0)
        res += (total_dist / range);
    else
        res += (total_dist / range) + 1;
}

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;

    for (int i = 0; i < stations.size(); i++) {
        if (i == 0)
            set_station(1, stations[i] - w - 1, w * 2 + 1);
        else
            set_station(stations[i - 1] + w + 1, stations[i] - w - 1, w * 2 + 1);
    }

    set_station(stations[stations.size() - 1] + w + 1, n, w * 2 + 1);

    answer = res;
    return answer;
}
