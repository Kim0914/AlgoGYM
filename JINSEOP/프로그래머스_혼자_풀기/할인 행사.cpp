#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> discount_list;
unordered_map<string, int> wish_list;
int res = 0;
void validate() {
    for (auto i : wish_list)
        if (discount_list[i.first] < i.second)
            return;

    res++;
}

void make_wish_list(vector<string> want, vector<int> number) {
    for (int i = 0; i < want.size(); i++)
        wish_list[want[i]] = number[i];
}

void look_ten_days(vector<string> discount) {
    int size = discount.size();

    for (int i = 0; i < 10; i++)
        discount_list[discount[i]]++;
    validate();

    for (int std = 0; std < size - 10; std++) {
        discount_list[discount[std]]--;
        discount_list[discount[std + 10]]++;
        validate();
    }
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;

    make_wish_list(want, number);
    look_ten_days(discount);
    answer = res;

    return answer;
}

// 뭔가 최적화가 더 가능할 것 같은 기분이다.
// 시도 해봐야 할 것 같다.
