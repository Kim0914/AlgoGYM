#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;


unordered_map<string, string> pedigree; // <본인, 추천인> 관계를 저장
unordered_map<string, int> revenue; // <본인, 소득> 관계를 저장

void calc_revenue(string name, int profit) {
    if (name == "minho") return;
    // 추천인이 Center와 같으면 종료.

    int commission = profit * 0.1; // 상납금
    revenue[name] += profit - commission; 
    if (commission < 1) return; // 계산한 값이 1 이하면 상납하지 않는다.

    calc_revenue(pedigree[name], commission);
    // 부모로 쭉쭉 타고 올라가도록 재귀.
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;

    for (int i = 0; i < referral.size(); i++) {
        if (referral[i] == "-") pedigree[enroll[i]] = "minho";
        else pedigree[enroll[i]] = referral[i];
    } // 추천인 저장.

    for (int i = 0; i < seller.size(); i++)
        calc_revenue(seller[i], amount[i] * 100);

    for (int i = 0; i < enroll.size(); i++)
        answer.push_back(revenue[enroll[i]]);

    return answer;
}
