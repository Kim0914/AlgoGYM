#include <iostream>
#include <unordered_map>
using namespace std;
#define ll long long

ll n = 0, p = 0, q = 0;
unordered_map<int, int> hash_table;
int calculate_sequence(ll target) {
	if (target == 0)
		return hash_table[0];

	hash_table[target] = calculate_sequence(target / p) + calculate_sequence(target / q);
	return hash_table[target];
}

int main() {
	cin >> n >> p >> q;
	hash_table[0] = 1; // 초항 init
	
	calculate_sequence(n);
	cout << hash_table[n];
	return 0;
}
