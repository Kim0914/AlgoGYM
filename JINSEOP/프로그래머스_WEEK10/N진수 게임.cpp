#include <string>
#include <vector>
#include <algorithm>
using namespace std;

char convert_to_hex(int n) {
    switch (n)
    {
    case 10:
        return 'A';
    case 11:
        return 'B';
    case 12:
        return 'C';
    case 13:
        return 'D';
    case 14:
        return 'E';
    case 15:
        return 'F';
    }
}

string make_line(int n, int limit) {
    string line = "", temp = "";
    int target = 1, key = 0;

    line += '0';

    while (true) {
        string temp = "";
        key = target;

        while (key != 0) {
            int remain = key % n;
            if (remain >= 10)
                temp += convert_to_hex(remain);
            else
                temp += to_string(remain);
            key /= n;
        }

        reverse(temp.begin(), temp.end());
        line += temp;
        if (line.size() > limit) break;
        target++;
    }

    return line;
}

string cut_line(string line, int limit) {
    return line.substr(0, limit);
}

string make_answer(string line, int m, int p) {
    string answer = "";

    for (int i = 0; i < line.size(); i++) {
        if (i % m == (p - 1)) 
            answer += line[i];
    }

    return answer;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string line = "";
    int limit = t * m;

    line = make_line(n, limit);
    line = cut_line(line, limit);
    answer = make_answer(line, m, p);

    return answer;
}
