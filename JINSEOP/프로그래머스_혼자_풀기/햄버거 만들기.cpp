#include <string>
#include <vector>
#include <stack>
using namespace std;

stack<int> hamburger;
int solution(vector<int> ingredient) {
    int answer = 0;
    // 기본 순서는 1 2 3 1

    for (int i = 0; i < ingredient.size(); i++) {
        hamburger.push(ingredient[i]);
    }

    return answer;
}

int main() {
    vector<int> ingredient = { 2, 1, 1, 2, 3, 1, 2, 3, 1 };
    solution(ingredient);
    return 0;
}
