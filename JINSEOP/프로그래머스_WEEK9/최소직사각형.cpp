#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int hor_max_size = 0, ver_max_size = 0;

    for (int i = 0; i < sizes.size(); i++) {
        if (sizes[i][0] < sizes[i][1]) {
            swap(sizes[i][0], sizes[i][1]);
        }
        
        if (hor_max_size < sizes[i][0]) hor_max_size = sizes[i][0];
        if (ver_max_size < sizes[i][1]) ver_max_size = sizes[i][1];
    }

    answer = hor_max_size * ver_max_size;
    return answer;
}
