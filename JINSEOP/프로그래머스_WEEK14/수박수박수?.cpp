#include <string>
#include <vector>
using namespace std;

string add_water_and_melon(int n){
    string temp = "";
    int cnt = 0;
    
    while(cnt != n){
        if(cnt % 2 == 0)
            temp += "수";
        else
            temp += "박";
        cnt++;
    }
    
    return temp;
}

string solution(int n) {
    string answer = "";
    
    answer = add_water_and_melon(n);
    return answer;
}
