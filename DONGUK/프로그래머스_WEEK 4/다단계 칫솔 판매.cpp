#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<string, int> user_profit;
map<string, int> user_index;

void dfs(string name, int price, vector<string> &referral){
    if (name == "-") return;
    
    if (price < 10){
        user_profit[name] += price;
        return;
    }
    
    user_profit[name] += (price - int(price * 0.1));
    
    
    int ind = user_index[name];
    string candidator = referral[ind];
    
    dfs(candidator, price * 0.1, referral);

}


vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    
    for(int i=0; i<enroll.size(); i++){
        user_profit[enroll[i]] = 0;
        user_index[enroll[i]] = i;
    }
    

    // max 100,000
    for(int i=0; i<seller.size(); i++){
        string name = seller[i];
        int price = amount[i] * 100;
        int ind = user_index[name];
        
        user_profit[name] += price * 0.9;
        string candidator = referral[ind];
        
        dfs(candidator, price * 0.1, referral);
    }
    
    for(string name: enroll){
        answer.push_back(user_profit[name]);
    }
    
    return answer;
}