#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> price;
    for(int i = 0; i < prices.size(); i++){
        while(!price.empty() && prices[price.top()] > prices[i]){
            answer[price.top()] = i - price.top();
            price.pop();
        }
        price.push(i);
    }
    while(!price.empty()){
        answer[price.top()] = prices.size() - 1 - price.top();
        price.pop();
    }
    for(auto i : answer){
        cout << i << " ";
    }
    return answer;
}
