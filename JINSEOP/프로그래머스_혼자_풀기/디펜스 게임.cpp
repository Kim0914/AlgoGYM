#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> classifer;
int solution(int n, int k, vector<int> enemy) {
    int cost = 0;
    int enemies = enemy.size();

    for (int i = 0; i < enemy.size(); i++) {
        classifer.push(enemy[i]);

        if (classifer.size() > k) {
            cost += classifer.top();
            classifer.pop();
        }

        if (cost > n)
            return i;
    }

    return enemies;
}
