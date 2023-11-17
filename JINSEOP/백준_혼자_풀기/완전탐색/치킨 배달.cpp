#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int num = 0, city_chicken_distance = 99999999, chicken_num = 0, city_map[50][50];
bool chicken_visit[13];
vector<pair<int, int>> house_vec;
vector<pair<int, int>> chicken_vec;
vector<pair<int, int>> selected_chicken;
void optimize() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int calculate_distance() {
    int distance_sum = 0;

    for (int i = 0; i < house_vec.size(); i++) {
        int house_x = house_vec[i].first;
        int house_y = house_vec[i].second;
        int min_dist = 99999999;

        for (int j = 0; j < selected_chicken.size(); j++) {
            int chicken_x = selected_chicken[j].first;
            int chicken_y = selected_chicken[j].second;
            int dist = abs(house_x - chicken_x) + abs(house_y - chicken_y);

            min_dist = min(dist, min_dist);
        }

        distance_sum += min_dist;
    }

    return distance_sum;
}

void backtrack(int idx) {
    if (selected_chicken.size() == chicken_num) {
        city_chicken_distance = min(city_chicken_distance, calculate_distance());
        return;
    }

    for (int i = idx; i < chicken_vec.size(); i++) {
        if (!chicken_visit[i]) {
            selected_chicken.push_back(chicken_vec[i]);
            chicken_visit[i] = true;
            backtrack(i);
            selected_chicken.pop_back();
            chicken_visit[i] = false;
        }
    }
}

int main() {
    optimize();

    cin >> num >> chicken_num;
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            cin >> city_map[i][j];
            if (city_map[i][j] == 1)
                house_vec.push_back({ i, j });
            if(city_map[i][j] == 2)
                chicken_vec.push_back({i, j});
        }
    }

    backtrack(0);
    cout << city_chicken_distance;

    return 0;
}
