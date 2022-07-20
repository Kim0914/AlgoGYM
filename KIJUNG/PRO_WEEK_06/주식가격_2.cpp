#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for(int i=0;i<prices.size();i++){
        answer.push_back(prices.size()-i-1);
    }

    for(int i=prices.size()-1;i>=0;i--){
        for(int j=i-1;j>=0;j--){
            if(prices[j]<=prices[i]) break;
            answer[j] = i-j;
        }
    }

    return answer;
}
//worst 케이스 계산하기 너무 어렵.. 대충 1억정도 되는 것 같다.