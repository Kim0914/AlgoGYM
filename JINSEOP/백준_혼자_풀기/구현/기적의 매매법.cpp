#include <iostream>
#include <queue>
using namespace std;

int j_seed = 0, s_seed = 0, j_stock = 0, s_stock = 0, stock[14];
void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	optimize();
	cin >> j_seed;
	s_seed = j_seed;
	for (int i = 0; i < 14; i++)
		cin >> stock[i];

	// 준현 매매법
	for (int i = 0; i < 14; i++) {
		if (j_seed < stock[i])
			continue;
		
		int coef = 1;
		while (true) {
			if (j_seed < stock[i] * coef) {
				coef--;
				break;
			}
			
			coef++;
		}

		j_stock += coef;
		j_seed -= (stock[i] * coef);
	}

	// 성민 매매법
	int i_count = 0, d_count = 0;
	for (int i = 1; i < 14; i++) {
		if (stock[i - 1] < stock[i]) {
			i_count++;
			d_count = 0;
		}
		else if (stock[i - 1] > stock[i]) {
			d_count++;
			i_count = 0;
		}
		else if (stock[i - 1] == stock[i]) {
			i_count = 0;
			d_count = 0;
		}

		if (d_count >= 3) {
			// 전량 매수
			int coef = 1;

			while (true) {
				if (s_seed < stock[i] * coef) {
					coef--;
					break;
				}

				coef++;
			}

			s_stock += coef;
			s_seed -= (stock[i] * coef);
		}
		
		if (i_count >= 3) {
			// 전량 매도
			s_seed += stock[i] * (s_stock);
			s_stock = 0;
		}
	}

	int j_asset = (stock[13] * j_stock) + j_seed;
	int s_asset = (stock[13] * s_stock) + s_seed;
	if (j_asset > s_asset)
		cout << "BNP";
	if (j_asset < s_asset)
		cout << "TIMING";
	if (j_asset == s_asset)
		cout << "SAMESAME";

	return 0;
}
