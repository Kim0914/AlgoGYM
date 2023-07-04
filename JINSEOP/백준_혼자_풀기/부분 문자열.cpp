#include <iostream>
#include <vector>
using namespace std;

vector<int> calculate_pi(string dest) {
    vector<int> pi(dest.size(), 0);
    int cursor = 0;

    for (int i = 1; i < dest.size(); i++) {
        while (dest[i] != dest[cursor] && cursor > 0) {
            cursor = pi[cursor-1]; // 일치하지 않으면 j를 일치할 때 까지 뒤로
        }
        if (dest[i] == dest[cursor]) {
            cursor += 1; // 일치하면 j도 앞으로
            pi[i] = cursor; // 해당 시점에서의 pi
            // pi는 접두사 == 접미사인 문자열의 길이
        }
    }
  
    return pi;
}

int kmp(string src, string dest, vector<int>& pi) {
    int cursor = 0;

    for (int i = 0; i < src.size(); i++) {
        while (src[i] != dest[cursor] && cursor > 0) {
            cursor = pi[cursor - 1];
        }
        if (src[i] == dest[cursor]) {
            cursor++;
            if (cursor == dest.size())
                return 1; // 커서가 끝까지 이동했으면 부분 문자열!
        }
    }

    return 0;
}

int main() {
    string src = "", dest = "";
    cin >> src >> dest;

    vector<int> pi = calculate_pi(dest);
    cout << kmp(src, dest, pi);
    
    return 0;
}
