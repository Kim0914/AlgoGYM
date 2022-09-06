#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

unordered_map<string, int> multiset1;
unordered_map<string, int> multiset2;
unordered_set<string> store;
void init(string& str1, string& str2) {
    for (int i = 0; i < str1.size(); i++)
        str1[i] = tolower(str1[i]);
    for (int i = 0; i < str2.size(); i++)
        str2[i] = tolower(str2[i]);
}

void make_multiset(string str1, string str2) {
    for (int i = 0; i < str1.size() - 1; i++) {
        if ((str1[i] >= 'a' && str1[i] <= 'z') && (str1[i + 1] >= 'a' && str1[i + 1] <= 'z')) {
            string partial1 = str1.substr(i, 2);
            multiset1[partial1]++;
            store.insert(partial1);
        }
    }
    for (int i = 0; i < str2.size() - 1; i++) {
        if ((str2[i] >= 'a' && str2[i] <= 'z') && (str2[i + 1] >= 'a' && str2[i + 1] <= 'z')) {
            string partial2 = str2.substr(i, 2);
            multiset2[partial2]++;
            store.insert(partial2);
        }
    }
}

int calc_jaccard() {
    double inter = 0.0, uni = 0.0;

    for (auto s : store) {
        inter += min(multiset1[s], multiset2[s]);
        uni += max(multiset1[s], multiset2[s]);
    }
    
    if (uni == 0) return 65536;
    return (inter / uni) * 65536;
}

int solution(string str1, string str2) {
    int answer = 0;
    
    init(str1, str2);
    make_multiset(str1, str2);
    answer = calc_jaccard();

    return answer;
}
