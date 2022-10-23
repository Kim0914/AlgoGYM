#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;

    sort(routes.begin(), routes.end());
    int curr_camera = routes[0][1];

    for (int i = 1; i < routes.size(); i++) {
        if (curr_camera < routes[i][0]) {
            answer++;
            curr_camera = routes[i][1];
        }
        if (routes[i][1] <= curr_camera)
            curr_camera = routes[i][1];
    }

    return answer;
}
