#include <iostream>
#include <string>
using namespace std;

int tc = 0;
string target = "";
void optimize() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool fold_paper(int left, int right) {
    if (left >= right)
        return true;
    
    int mid = (left + right) / 2;
    for (int i = 0; i < (mid - left); i++) {
        if (target[left + i] == target[right - i])
            return false;
    }

    return fold_paper(left, mid - 1);
}

int main(){
    optimize();
    cin >> tc;
    for (int i = 0; i < tc; i++) {
        cin >> target;

        if (target.size() == 1) {
            cout << "YES" << '\n';
            continue;
        }

        if (fold_paper(0, target.size() - 1))
            cout << "YES" << '\n';
        else
            cout << "NO" << "\n";
    }

    return 0;
}
