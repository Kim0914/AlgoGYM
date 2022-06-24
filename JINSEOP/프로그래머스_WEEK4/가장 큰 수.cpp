#include <string>
#include <vector>
#include <queue>
using namespace std;

struct cmp {
    bool operator()(string a, string b) {
        return a + b < b + a; // 핵심 
    }
};
priority_queue<string, vector<string>, cmp> classifier;

string make_answer(string answer) {
    while (!classifier.empty()) {
        answer += classifier.top();
        classifier.pop();
    }
    
    return answer;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    for (int i = 0; i < numbers.size(); i++)
        classifier.push(to_string(numbers[i]));
    
    answer = make_answer(answer);
    
    return (answer[0] == '0') ? "0" : answer;
}
