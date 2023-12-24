#include <iostream>
using namespace std;

string src = "", dest = "";
int lcs[4001][4001], answer = 0;
int main() {
	cin >> src >> dest;
	
	for (int i = 1; i <= src.size(); i++) {
		for (int j = 1; j <= dest.size(); j++) {
			if (src[i-1] == dest[j-1]) {
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
				answer = max(answer, lcs[i][j]);
			}
		}
	}

	cout << answer;
	return 0;
}
