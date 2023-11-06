#include <iostream>
#include <string>
using namespace std;

string target = "";
int main(){
	cin >> target;

	int num = 1, iter = 0;
	string temp_of_num = "";
	while (true) {
		temp_of_num = to_string(num);

		for (int i = 0; i < temp_of_num.size(); i++) {
			if(target[iter] == temp_of_num[i])
				iter++;
		}

		if (iter == target.size())
			break;

		num++;
	}

	cout << num;
	return 0;
}
