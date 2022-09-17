#include <string>
using namespace std;

void protect_number(string& phone_number) {
    for (int i = phone_number.size() - 5; i >= 0; i--)
        phone_number[i] = '*';
}

string solution(string phone_number) {
    string answer = "";

    protect_number(phone_number);
    answer = phone_number;
    return answer;
}
