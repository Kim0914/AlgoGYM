#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int num = 0;
double liter = 0, answer = 0;
vector<double> drinks;
int main(){
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> liter;
		drinks.push_back(liter);
	}

	sort(drinks.begin(), drinks.end());

	answer = drinks[drinks.size() - 1];
	for (int i = 0; i < drinks.size() - 1; i++) 
		answer += (drinks[i] / 2);

	cout << answer;
	return 0;
}
