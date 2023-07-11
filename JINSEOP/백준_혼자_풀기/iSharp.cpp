#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string cmd = "", base_type ="", name = "", additional_type = "", buffer = "";

	getline(cin, cmd);
	base_type = "";
	for (int i = 0; i < cmd.size(); i++) {
		if (cmd[i] == ' ') {
			buffer = "";
			for (int j = i + 1; j < cmd.size(); j++)
				buffer += cmd[j];

			cmd = buffer;
			break;
		}
		else
			base_type += cmd[i];
	}

	int iter = 0;
	while (iter < cmd.size()){
		if (cmd[iter] == ',' || cmd[iter] == ';') {
			buffer = "";
			for (int j = additional_type.size() - 1; j >= 0; j--) { // Reverse
				if (additional_type[j] == '[') // 반대로 넣어야함
					buffer += ']';
				else if (additional_type[j] == ']')
					buffer += '[';
				else
					buffer += additional_type[j];
			}

			cout << base_type << buffer << " " << name << ";" << "\n";
			name = "";
			additional_type = "";

			if (cmd[iter] == ';')
				break;
			else
				iter += 2; // ,와 공백까지 넘기기
		}
		else if ((cmd[iter] >= 'a' && cmd[iter] <= 'z') || (cmd[iter] >= 'A' && cmd[iter] <= 'Z')) {
			name += cmd[iter];
			iter++;
		}
		else {
			additional_type += cmd[iter];
			iter++;
		}
	}

	return 0;
}
