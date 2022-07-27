#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int maxX = 0;
    int maxY = 0;
    sort(sizes.begin(), sizes.end());
    for(vector<int> size: sizes){
        sort(size.begin(), size.end());
        maxX = max(maxX, size[0]);
        maxY = max(maxY, size[1]);
    }
    return maxX*maxY;
}