#include <string>
#include <vector>
using namespace std;

void ternary(int n, string& answer) {
    while (n != 0) {
        if (n % 3 == 0) {
            answer = "4" + answer;
            n--;
        }
        else if (n % 3 == 2)
            answer = "2" + answer;
        else if (n % 3 == 1)
            answer = "1" + answer;

        n /= 3;
    }
}

string solution(int n) {
    string answer = "";

    ternary(n, answer);
    return answer;
}
