#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;
    for (int i = 0; i < s.size(); i++) {
        int zero_cnt = 0;
        string result_str = "";

        for (int j = 0; j < s[i].size(); j++) {
            result_str += s[i][j];

            if (result_str.size() >= 3) {
                if (result_str.substr(result_str.size() - 3, 3) == "110") {
                    zero_cnt++;
                    result_str.erase(result_str.size() - 3, result_str.size());
                }
            }
        }

        int zero_pos = -1;
        for (int j = result_str.size() - 1; j >= 0; j--) {
            if (result_str[j] == '0') {
                zero_pos = j;
                break;
            }
        }

        string temp = "";
        if (zero_pos == -1) {
        // 문자열에 0이 없는 경우
            while (zero_cnt--)
                temp += "110";

            temp += result_str;
            answer.push_back(temp);
        }
        else {
            for (int j = 0; j < result_str.size(); j++) {
                if (j == zero_pos) {
                    temp += result_str[j];
                    while (zero_cnt--)
                        temp += "110";
                }
                else
                    temp += result_str[j];
            }

            answer.push_back(temp);
        }
    }

    return answer;
}

int main() {
    solution({"1100111011101001" });
	return 0;
}
