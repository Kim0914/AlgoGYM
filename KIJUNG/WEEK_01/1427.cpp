#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s;

bool desc(char a, char b){return a>b;}

int main(void){
    cin >> s;

    sort(s.begin(), s.end(), desc);

    cout << s;

    return 0;
}// 시간복잡도가 nlog(n)인 알고리즘. n:숫자의 길이