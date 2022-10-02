#include <iostream>
#include <string>
#include <vector>
using namespace std;

void encrypt(string& s, int n) {
    for (char& c : s) {
        if ('A' <= c && c <= 'Z')
            c = (c + (n - 'A')) % 26 + 'A';
        if ('a' <= c && c <= 'z')
            c = (c + (n - 'a')) % 26 + 'a';
    }
}

string solution(string s, int n) {
    string answer = "";

    encrypt(s, n);
    answer = s;

    return answer;
}
