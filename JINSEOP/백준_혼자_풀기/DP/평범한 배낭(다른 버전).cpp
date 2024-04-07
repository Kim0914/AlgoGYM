#include <iostream>
#include <vector>
using namespace std;

int num = 0, weight_limit = 0;
int dp[100001];
int main(){
	cin >> num >> weight_limit;

	int each_weight = 0, each_price = 0;
	for (int i = 0; i < num; i++) {
		cin >> each_weight >> each_price;

		for (int j = weight_limit; j >= each_weight; j--)
			dp[j] = max(dp[j], dp[j - each_weight] + each_price);
	}

	cout << dp[weight_limit];
	return 0;
}
