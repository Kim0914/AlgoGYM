#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> calculate_pi(string dest) {
    vector<int> pi(dest.size(), 0);
    int cursor = 0;

    for (int i = 1; i < dest.size(); i++) {
        while (dest[i] != dest[cursor] && cursor > 0) {
            cursor = pi[cursor-1];
            // 일치하지 않으면 이전 pi 값으로 커서를 옮김
            // 이전 pi 값이 의미하는 바는 이전까지 일치했던 위치
            // 이는 (현재 위치 - 일치하는 길이) 만큼 옮긴 것!
        }
        if (dest[i] == dest[cursor]) {
            cursor += 1; // 일치하면 커서와 i 모두 앞으로
            pi[i] = cursor; 
            // 해당 시점에서의 pi, 겹칠 수록 점점 커짐
            // pi는 접두사 == 접미사인 문자열의 길이
        }
    }

    return pi;
}

vector<int> do_kmp(string src, string dest, vector<int>& pi) {
    // KMP 알고리즘 또한, pi 배열을 구하는 것과 동일한 구조이다.
    int cursor = 0;

    vector<int> result;
    for (int i = 0; i < src.size(); i++) {
        while (src[i] != dest[cursor] && cursor > 0) {
            cursor = pi[cursor - 1];
        }
        if (src[i] == dest[cursor]) {
            if (cursor == dest.size() - 1) { // -1인 이유는, 커서가 0부터라서
                result.push_back(i - dest.size() + 1);
                cursor = pi[cursor];
            }
            else {
                cursor++;
            }
        }
    }

    return result;
}

int main() {
    string src = "", dest = "";
    getline(cin, src);
    getline(cin, dest);

    vector<int> pi = calculate_pi(dest);
    vector<int> result = do_kmp(src, dest, pi);

    cout << result.size() << endl;
    for (auto i : result)
        cout << i + 1 << " ";
    
    return 0;
}
