#include <string>
#include <vector>
using namespace std;

void convert_to_zero(int pos, string& target) {
    target[pos] = '1';
    target[pos + 1] = '1';
    target[pos + 2] = '0';
}

void convert_to_one(int dest, int src, string& target) {
    for (int i = dest; i > src; i--)
        target[i] = '1';
}

vector<string> solution(vector<string> s) {
    vector<string> answer;

    for (int i = 0; i < s.size(); i++) {
    // 앞에서부터 111을 찾아, 110으로 치환하자!
        string partition = "";
        int src = 0, dest = 0, iter = 0;
        while(true){
            bool find_one = false, find_zero = false;
            for (int j = iter; j < s[i].size(); j++) {
                partition += s[i][j];
                if (partition.size() > 3)
                    partition = partition.substr(1);

                if (!find_one && partition == "111") {
                    src = j;
                    find_one = true;
                }
                if (!find_zero && partition == "110") {
                    dest = j;
                    find_zero = true;
                }

                if (find_one && find_zero)
                    break;
            }

            if (!find_one || !find_zero)
                break;
 
            iter = src + 1;
            if (src > dest)
                continue; // 111보다 110을 앞에서 찾은 경우

            convert_to_zero(src - 2, s[i]);
            convert_to_one(dest, src, s[i]);
        }

        answer.push_back(s[i]);
    }

    return answer;
}

int main() {
    solution({ "1110", "100111100", "0111111010" });
	return 0;
}
