#include <string>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    string photo = "ACFJMNRT";
    
    do{
        bool flag = true;

        for(int i=0; i<n; i++){
            char a = data[i][0];
            char b = data[i][2];
            char sign = data[i][3];
            int target = data[i][4] - '0';
            
            int a_ind = photo.find(a);
            int b_ind = photo.find(b);
            
            int dis = abs(a_ind - b_ind) - 1;
            if(sign == '>'){
                if (dis <= target){
                    flag = false;
                    break;
                }
            }
            
            else if(sign == '<'){
                if (dis >= target){
                    flag = false;
                    break;
                }
            }
            
            else if(sign == '='){
                if (dis != target){
                    flag = false;
                    break;
                }
            }
            
            else continue;
        }
        
        if (flag == true){
            answer += 1;
        }
    }
    while(next_permutation(photo.begin(), photo.end()));
    

    return answer;
}