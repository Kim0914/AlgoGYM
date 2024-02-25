#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;

    for (int i = 0; i < s.size(); i++) {
        int zero_cnt = 0;

        while (true) {
            // 여기서 110을 모두 찾아서 제거함
            int pos = s[i].find("110");

            if (pos == -1)
                break;
            else
                zero_cnt++;

            s[i].erase(pos, 3);
        }

        while (zero_cnt--) {
            int zero_pos = -1;
            string temp_substr_front = "", temp_substr_rear = "";

            for (int j = s[i].size() - 1; j >= 0; j--) {
                if (s[i][j] == '0') {
                    zero_pos = j;
                    break;
                }
            }

            if (zero_pos == -1)
                s[i] = "110" + s[i];
            else {
                temp_substr_front = s[i].substr(0, zero_pos + 1);
                temp_substr_rear = s[i].substr(zero_pos + 1);

                s[i] = temp_substr_front + "110" + temp_substr_rear;
            }
        }

        answer.push_back(s[i]);
    }

    return answer;
}

int main() {
    solution({"1100111011101001" });
	return 0;
}
