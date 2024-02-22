#include <iostream>
using namespace std;

string str1 = "", str2 = "", str3 = "";
int dp[101][101][101];
int main() {
	cin >> str1;
	cin >> str2;
	cin >> str3;

	for (int i = 1; i <= str3.size(); i++) {
		for(int j = 1; j <= str2.size(); j++){
			for (int k = 1; k <= str1.size(); k++) {
				if (str1[k - 1] == str2[j - 1] && str2[j - 1] == str3[i - 1])
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				else
					dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
			}
		}
	}

	cout << dp[str3.size()][str2.size()][str1.size()];
	return 0;
}
