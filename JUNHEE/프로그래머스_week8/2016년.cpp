#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int a, int b) {
    string week[7] = {"THU","FRI","SAT","SUN","MON","TUE","WED"};
    int month[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    string answer = "";
    int day = 0;
    a -= 1;
    for(int i = 0; i < a; i++){
        day += month[i];
    }
    day += b;
    cout << day;
    answer =  week[day % 7];
    return answer;
}
