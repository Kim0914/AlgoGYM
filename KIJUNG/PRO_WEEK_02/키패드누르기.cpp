#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int distance(char current, char target){
    int currentX, currentY, targetX, targetY;
    if(current == '*'){
        currentX = 1;
        currentY = 4;
    }
    else if(current == '#'){
        currentX = 3;
        currentY = 4;
    }
    else if(current == '0'){
        currentX = 2;
        currentY = 4;
    }
    else{
        currentX = ((current-48)%3 == 0)? 3:(current-48)%3;
        currentY = (current-48)/3+1;
        currentY -= (currentX==3)? 1:0;
    }

    if(target == '0'){
        targetX = 2;
        targetY = 4;
    }
    else{
        targetX = ((target-48)%3 == 0)? 3:(target-48)%3;
        targetY = (target-48)/3+1;
        targetY -= (targetX==3)? 1:0;
    }
    return abs(currentX - targetX) + abs(currentY - targetY);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";

    char left = '*';
    char right = '#';


    for(char n: numbers){
        
        n+=48;
        if(n == '1' || n == '4' || n == '7'){
            left = n;
            answer += "L";
        }
        else if(n == '3' || n == '6' || n == '9'){
            right = n;
            answer += "R";
        }
        else{
            int leftDist = distance(left, n);
            int rightDist = distance(right, n);

            if(leftDist == rightDist){
                if(hand == "left"){
                    left = n;
                    answer += "L";
                }
                else{
                    right = n;
                    answer += "R";
                }
            }
            else if(leftDist > rightDist){
                right = n;
                answer += "R";
            }
            else{
                left = n;
                answer += "L";
            }
        }
    }

    return answer;
}