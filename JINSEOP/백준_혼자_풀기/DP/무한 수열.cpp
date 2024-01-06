#include <iostream>
#include <unordered_map>
using namespace std;
#define ll long long

ll n = 0, p = 0, q = 0;
unordered_map<ll, ll> hash_table;
ll calculate_sequence(ll target) {
	if (target == 0)
		return 1;

	ll& ret = hash_table[target];
	if (ret != 0)
		return ret;

	return ret = calculate_sequence(target / p) + calculate_sequence(target / q);
}

int main() {
	cin >> n >> p >> q;
	
	cout << calculate_sequence(n);
	return 0;
}
