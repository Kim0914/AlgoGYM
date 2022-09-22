#include <string>
#include <vector>
#include <cmath>
using namespace std;

string oper_pri = "*-+";
long long max_v = 0;
bool visit[3] = { 0, };
vector<char> opers;
vector<long long> nums;
void parse_expression(string expression) {
    string temp = "";

    for (char c : expression) {
        if ('0' <= c && c <= '9') 
            temp += c;
        else {
            nums.push_back(stoll(temp)); 
            temp = "";
            opers.push_back(c);
        }
    }

    nums.push_back(stoll(temp));
}

long long calculate_unit(long long a, long long b, char oper) {
    switch (oper)
    {
    case '*':
        return a * b;
    case '-':
        return a - b;
    case '+':
        return a + b;
    }
}

long long calculate_expression(string priority) {
    vector<char> temp_opers = opers;
    vector<long long> temp_nums = nums;

    for (int prio = 0; prio < 3; prio++) {
        char curr_oper = priority[prio];

        for (int i = 0; i < temp_opers.size(); i++) {
            if (temp_opers[i] == curr_oper) {
                long long res = calculate_unit(temp_nums[i], temp_nums[i + 1], curr_oper);
                temp_nums[i] = res;
                temp_nums.erase(temp_nums.begin() + i + 1);
                temp_opers.erase(temp_opers.begin() + i);
                i--;
            }
        }
    }

    return abs(temp_nums[0]);
}

void make_priority(int idx, string priority) {
    if (priority.size() == 3) {
        long long result = calculate_expression(priority);
        if (max_v < result)
            max_v = result;

        return;
    }

    for (int i = 0; i < 3; i++) {
        if (!visit[i]) {
            priority += oper_pri[i];
            visit[i] = true;
            make_priority(i, priority);
            priority.pop_back();
            visit[i] = false;
        }
    }
}

long long solution(string expression) {
    long long answer = 0;

    parse_expression(expression);
    make_priority(0, "");
    answer = max_v;

    return answer;
}
