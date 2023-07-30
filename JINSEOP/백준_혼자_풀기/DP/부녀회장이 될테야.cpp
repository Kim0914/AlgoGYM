#include <vector>
#include <iostream>
using namespace std;
int DP[15][15];

void fill_dp() {
    for (int i = 1; i < 15; i++)
        DP[0][i] = i;

    for (int i = 1; i < 15; i++) {
        for (int j = 1; j < 15; j++) {
            DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
        }
    }
}

int main() {
    int t = 0, floor = 0, room = 0;
    fill_dp();

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> floor >> room;
        cout << DP[floor][room] << "\n";
    }

    return 0;
}
