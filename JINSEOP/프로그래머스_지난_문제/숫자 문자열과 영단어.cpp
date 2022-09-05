#include <string>
#include <vector>
using namespace std;

string numtring[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

int tokenize(string s) {
    for (int i = 0; i < 10; i++)
        if (s == numtring[i]) return i;

    return -1;
}

string string_to_number(string s) {
    string res = "";
    string temp = "";
    for (auto c : s) {
        if (c >= 'a' && c <= 'z')
            temp += c;
        else
            res += c;

        int converted = tokenize(temp);
        if (converted >= 0) {
            res += converted + '0';
            temp = "";
        }
    }

    return res;
}

int solution(string s) {
    int answer = 0;

    answer = stoi(string_to_number(s));

    return answer;
}
