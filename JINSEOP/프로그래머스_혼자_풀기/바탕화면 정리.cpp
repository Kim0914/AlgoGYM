#include <string>
#include <vector>
using namespace std;

vector<int> scan_desktop(vector<string> wallpaper) {
    vector<int> coordinate;

    int lux = 0, luy = 0, rdx = 0, rdy = 0;
    bool is_first = false;

    for (int i = 0; i < wallpaper[0].size(); i++) {
        for (int j = 0; j < wallpaper.size(); j++) {
            if (wallpaper[j][i] == '#') {
                rdy = i;

                if (!is_first) {
                    luy = i;
                    is_first = true;
                }
            }
        }
    }

    is_first = false;
    for (int i = 0; i < wallpaper.size(); i++) {
        for (int j = 0; j < wallpaper[0].size(); j++) {
            if (wallpaper[i][j] == '#') {
                rdx = i;

                if (!is_first) {
                    lux = i;
                    is_first = true;
                }
            }
        }
    }

    return coordinate = { lux, luy, rdx + 1, rdy + 1 };
}

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    answer = scan_desktop(wallpaper);
    return answer;
}

// Brute force
