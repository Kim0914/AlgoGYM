#include <vector>
#include <iostream>
using namespace std;
int DP[31][31];

void fill_dp() {
    for (int i = 1; i < 31; i++)
        DP[i][i] = 1;
    for (int i = 1; i < 31; i++)
        DP[1][i] = i;

    for (int i = 2; i < 31; i++) {
        for (int j = i + 1; j < 31; j++) {
            DP[i][j] = DP[i][j-1] + DP[i - 1][j - 1];
        }
    }
}

int main() {
    int t = 0, n = 0, m = 0;
    fill_dp();

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> m;
        cout << DP[n][m] << "\n";
    }

    return 0;
}
