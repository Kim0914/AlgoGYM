#include <string>
#include <vector>
#include <map>

using namespace std;

void dfs(string seller, int amount, map<string,string> &referralMap, map<string,int> &sellMoney){
    if(amount == 0) return;
    int referMoney = amount/10;
    sellMoney[seller] += amount-referMoney;
    if(referralMap[seller] != "-"){
        dfs(referralMap[seller], referMoney, referralMap, sellMoney);
    }
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    map<string, string> referralMap;
    map<string, int> sellMoney;

    for(int i=0;i<enroll.size();i++){
        referralMap[enroll[i]] = referral[i];
    }

    for(int i=0;i<seller.size();i++){
        dfs(seller[i], amount[i]*100, referralMap, sellMoney);
    }

    for(string e: enroll){
        answer.push_back(sellMoney[e]);
    }
    return answer;
}