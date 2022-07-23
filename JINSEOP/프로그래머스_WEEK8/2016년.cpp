#include <string>
#include <vector>
using namespace std;

string solution(int a, int b) {
    string answer = "";
    vector<string> days = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
    switch (a)
    {
    case 1:
        answer = days[(b % 7 + 4)%7];
        break;
    case 2:
        answer = days[(b % 7) % 7];
        break;
    case 3:
        answer = days[(b % 7 + 1) % 7];
        break;
    case 4:
        answer = days[(b % 7 + 4) % 7];
        break;
    case 5:
        answer = days[(b % 7 + 6) % 7];
        break;
    case 6:
        answer = days[(b % 7 + 2) % 7];
        break;
    case 7:
        answer = days[(b % 7 + 4) % 7];
        break;
    case 8:
        answer = days[(b % 7) % 7];
        break;
    case 9:
        answer = days[(b % 7 + 3) % 7];
        break;
    case 10:
        answer = days[(b % 7 + 5) % 7];
        break;
    case 11:
        answer = days[(b % 7 + 1) % 7];
        break;
    case 12:
        answer = days[(b % 7 + 3) % 7];
        break;
    }

    return answer;
}
