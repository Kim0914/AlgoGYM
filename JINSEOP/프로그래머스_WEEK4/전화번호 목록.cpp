#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    
    for (int i = 1; i < phone_book.size(); i++) {
        if (phone_book[i - 1][0] != phone_book[i][0]) continue;
        if (phone_book[i].find(phone_book[i - 1]) != string::npos) {
            answer = false; 
            break;
        }
    }

    return answer;
}
