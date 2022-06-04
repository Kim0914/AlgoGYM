#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool possible(char op, int dist, int len){
    if(op=='=') return dist==len;
    else if(op=='>') return dist>len;
    else return dist<len;
}

int solution(int n, vector<string> data) {
    int answer = 0;
    string order = "ACFJMNRT";

    do {
        bool check = true;

        for(string s : data){
            int idx1 = order.find(s[0]);
            int idx2 = order.find(s[2]);
            int dist = abs(idx1-idx2)-1;
            int len = s[4]-48;

            if(possible(s[3], dist, len)) continue;
            check = false;
            break;
        }
        if(check) answer++;
    } while ( next_permutation(order.begin() ,order.end()) );

    return answer;
}