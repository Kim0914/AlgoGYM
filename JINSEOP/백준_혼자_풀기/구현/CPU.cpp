#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, int> opcode_map;
bool use_constant = false;
void init_map() {
	opcode_map["ADD"] = 0; opcode_map["ADDC"] = 0;
	opcode_map["SUB"] = 1; opcode_map["SUBC"] = 1;
	opcode_map["MOV"] = 2; opcode_map["MOVC"] = 2;
	opcode_map["AND"] = 3; opcode_map["ANDC"] = 3;
	opcode_map["OR"] = 4; opcode_map["ORC"] = 4;
	opcode_map["NOT"] = 5;
	opcode_map["MULT"] = 6; opcode_map["MULTC"] = 6;
	opcode_map["LSFTL"] = 7; opcode_map["LSFTLC"] = 7;
	opcode_map["LSFTR"] = 8; opcode_map["LSFTRC"] = 8;
	opcode_map["ASFTR"] = 9; opcode_map["ASFTRC"] = 9;
	opcode_map["RL"] = 10; opcode_map["RLC"] = 10;
	opcode_map["RR"] = 11; opcode_map["RRC"] = 11;
}

string decimal_to_binary(int decimal, int size) {
	string binary_code = "";

	while (decimal != 0) {
		binary_code = to_string(decimal % 2) + binary_code;
		decimal /= 2;
	}

	for (int i = binary_code.size(); i < size; i++)
		binary_code = "0" + binary_code;

	return binary_code;
}

string make_opcode(string opcode) {
	string binary_code = "";

	binary_code += decimal_to_binary(opcode_map[opcode], 4);
	if (opcode[opcode.size() - 1] == 'C') { // 4번 bit
		use_constant = true;
		binary_code += "1";
	}
	else
		binary_code += "0";

	binary_code += "0"; // 5번 bit
	return binary_code;
}

int main() {
	int test_case = 0, rD = 0, rA = 0, rB = 0;
	string cmd = "", opcode = "", machine = "";

	cin >> test_case;
	init_map();

	for (int i = 0; i < test_case; i++) {
		cin >> opcode >> rD >> rA >> rB;
		machine = ""; use_constant = false;

		machine += make_opcode(opcode);
		machine += decimal_to_binary(rD, 3);
		machine += decimal_to_binary(rA, 3);
		if (!use_constant) {
			machine += decimal_to_binary(rB, 3);
			machine += "0";
		}
		else
			machine += decimal_to_binary(rB, 4);

		cout << machine << endl;
	}

	return 0;
}
