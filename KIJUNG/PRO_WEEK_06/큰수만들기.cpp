#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    int cur = 0;
    int numSize = number.size()-k;

    for(int i=0;i<numSize;i++){
        char maxNum = number[cur];
        int maxIdx = cur;

        for(int j=cur;j<k+i+1;j++){
            if(maxNum<number[j]){
                maxNum = number[j];
                maxIdx = j;
            }
        }
        answer += maxNum;
        cur = maxIdx+1;
    }

    return answer;
}