#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int row = (brown - 6) / 2;
    int col = 1;
    while(row >= col){
        if(row * col == yellow){
            break;
        }
        row--;
        col++;
    }
    answer.push_back(row + 2);
    answer.push_back(col + 2);
    return answer;
}
