#include <iostream>
#include <vector>
using namespace std;

bool alpha_map[26];
int limit = 0, total_words = 0;

//void analyze_words(vector<string> words) {
//    for (int i = 0; i < words.size(); i++) {
//        for (int j = 4; j < words[i].size() - 4; j++) {
//            // anta, tica 제외 안쪽 글자만 읽음
//            if (!alpha_map[words[i][j]]) {
//                alpha_map[words[i][j]] = 1;
//                alpha_list += words[i][j]; // 얘로 조합을 돌려야 함
//                alpha_map[words[i][j]] = 0;
//            }
//        }
//    }
//}

void init_map() {
    alpha_map['a' - 'a'] = true;
    alpha_map['n' - 'a'] = true;
    alpha_map['t' - 'a'] = true;
    alpha_map['i' - 'a'] = true;
    alpha_map['c' - 'a'] = true;
}

int validate(vector<string> words) { // 검사 함수
    int cnt = 0;

    for (int i = 0; i < words.size(); i++) {
        bool isValid = true;

        for (int j = 4; j < words[i].size() - 4; j++) {
            if (!alpha_map[words[i][j] - 'a']) {
                isValid = false;
                break;
            }
        }

        if (isValid)
            cnt++;
    }

    return cnt;
}

void make_combination(int idx, vector<string> words) { // 조합 함수
    if (limit == 0) {
        total_words = max(total_words, validate(words)); // 안에서 카운트
        return;
    }

    for (int i = idx; i < 26; i++) {
        if (alpha_map[i] == 0) {
            limit--;
            alpha_map[i] = true;
            make_combination(i, words);
            limit++;
            alpha_map[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num = 0, w = 0;
    string word = "";
    vector<string> words;
    cin >> num >> w;
    limit = w - 5; // a, n, t, i, c는 미리 빼놓자

    for (int i = 0; i < num; i++) {
        cin >> word;
        words.push_back(word);
    }
    
    if (w < 5)
        cout << total_words << '\n';
    else {
        init_map();
        //analyze_words(words);
        make_combination(0, words);
        cout << total_words << '\n';
    }

    return 0;
}
