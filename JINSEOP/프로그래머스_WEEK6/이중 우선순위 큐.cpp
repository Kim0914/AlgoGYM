#include <string>
#include <vector>
#include <set>
using namespace std;

set<int> balanced_tree;

int convert(string target) {
    string temp = "";
    for (int i = 2; i < target.size(); i++)
        temp += target[i];

    return stoi(temp);
}

void delete_element(int cmd) {
    if (balanced_tree.empty()) return;

    int max_v = *balanced_tree.begin();
    int min_v = *(--balanced_tree.end());
    if (cmd == 1) balanced_tree.erase(min_v);
    if (cmd == -1) balanced_tree.erase(max_v);
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    for (int i = 0; i < operations.size(); i++) {
        switch (operations[i][0])
        {
        case 'I':
            balanced_tree.insert(convert(operations[i]));
            break;
        case 'D':
            delete_element(convert(operations[i]));
            break;
        }
    }

    if (balanced_tree.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(*(--balanced_tree.end()));
        answer.push_back(*balanced_tree.begin());
    }
    return answer;
}
