#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<char, int> skip_dict;
void fill_dictionary(string skip) {
    for (char c : skip)
        skip_dict[c] = 1;
}

string decrypt_caeser(string cipher, int index){
    string plain_text = "";

    for (char c : cipher) {
        int cnt = 0;

        while (cnt < index) {

            c += 1;
            if (c > 122)
                c -= 26;

            if (skip_dict[c] == 1)
                continue;

            cnt++;
        }
        plain_text += c;
    }

    return plain_text;
}

string solution(string s, string skip, int index) {
    string answer = "";

    fill_dictionary(skip);
    answer = decrypt_caeser(s, index);

    return answer;
}
