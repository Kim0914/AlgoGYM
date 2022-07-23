#include <string>

using namespace std;

string solution(int a, int b) {
    string day[7] = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};
    int monthSize[12] = {0,31,60,91,121,152,182,213,244,274,305,335};
    int totalDay = monthSize[a-1] + b;
    return day[totalDay%7];
}