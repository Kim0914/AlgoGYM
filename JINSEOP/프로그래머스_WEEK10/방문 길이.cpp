#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

set<vector<pair<int, int>>> classifier;
void move_character(string dirs) {
    pair<int, int> coordinate = { 0, 0 };

    for (int i = 0; i < dirs.size(); i++) {
        vector<pair<int, int>> temp;
        switch (dirs[i])
        {
        case 'U':
            if (coordinate.second < 5) {
                temp.push_back(coordinate);
                coordinate.second++;
                temp.push_back(coordinate);
                sort(temp.begin(), temp.end());
                classifier.insert(temp);
            }
            break;
        case 'D':
            if (coordinate.second > -5) {
                temp.push_back(coordinate);
                coordinate.second--;
                temp.push_back(coordinate);
                sort(temp.begin(), temp.end());
                classifier.insert(temp);
            }
            break;
        case 'R':
            if (coordinate.first < 5) {
                temp.push_back(coordinate);
                coordinate.first++;
                temp.push_back(coordinate);
                sort(temp.begin(), temp.end());
                classifier.insert(temp);
            }
            break;
        case 'L':
            if (coordinate.first > -5) {
                temp.push_back(coordinate);
                coordinate.first--;
                temp.push_back(coordinate);
                sort(temp.begin(), temp.end());
                classifier.insert(temp);
            }
            break;
        }
    }
}

int solution(string dirs) {
    int answer = 0;
    
    move_character(dirs);
    answer = classifier.size();

    return answer;
}
