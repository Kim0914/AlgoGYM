#include <string>
#include <vector>
#include <climits>
using namespace std;

long long max_x = LLONG_MIN, max_y = LLONG_MIN, min_x = LLONG_MAX, min_y = LLONG_MAX;
vector<pair<long long, long long>> intersections;
vector<string> res;
void get_intersection(vector<vector<int>> line) {
    for (int i = 0; i < line.size(); i++) {
        for (int j = i+1; j < line.size(); j++) {
            long long x_numerator = (line[i][1] * line[j][2] * 1LL) - (line[i][2] * line[j][1] * 1LL);
            long long y_numerator = (line[i][2] * line[j][0] * 1LL) - (line[i][0] * line[j][2] * 1LL);
            long long denominator = (line[i][0] * line[j][1] * 1LL) - (line[i][1] * line[j][0] * 1LL);
            
            if (denominator == 0) continue;
            if (((x_numerator % denominator) != 0) || ((y_numerator % denominator) != 0))
                continue;

            long long x = x_numerator / denominator;
            long long y = y_numerator / denominator;
            intersections.push_back({ x, y });

            max_x = max(max_x, x); max_y = max(max_y, y);
            min_x = min(min_x, x); min_y = min(min_y, y);
        }
    }
}

vector<string> solution(vector<vector<int>> line) {

    get_intersection(line);

    string temp = string(max_x - min_x + 1, '.');
    vector<string> answer(max_y - min_y + 1, temp);

    for (auto intersection : intersections)
        answer[abs(intersection.second - max_y)][abs(intersection.first - min_x)] = '*';

    return answer;
}

// Long Long type 다루는 법을 생각해보자.
