#include <iostream>
using namespace std;

int lo_bound = 0, up_bound = 0, answer = 0;
bool sieve[1000001];
int main() {
	cin >> lo_bound >> up_bound;
	
	for (int i = 2; i <= up_bound; i++) {
		if (i >= lo_bound && !sieve[i])
			cout << i << '\n';

		for (int j = i; j <= up_bound; j += i)
			if (j % i == 0)
				sieve[j] = true; // 배수 관계이면 체크
	}

	return 0;
}
