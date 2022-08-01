#include <string>
#include <vector>
#include <iostream>
using namespace std;
int one = 0, zero = 0;
void recursion(int x_start, int y_start, int size, vector<vector<int>>& arr){
    int sum = 0;
    if(size == 1){
        if(arr[x_start][y_start] == 1){
            one++;
            return;
        }
        else{
            zero++;
            return;
        }
    }
    for(int i = x_start; i < x_start + size; i++){
        for(int j = y_start; j < y_start + size; j++){
            sum += arr[i][j];
        }
    }
    if(size * size == sum){
        one++;
        return;
    }
    else if(sum == 0){
        zero++;
        return;
    }
    recursion(x_start,y_start,size/2,arr);
    recursion(x_start + size/2,y_start,size/2,arr);
    recursion(x_start,y_start + size/2,size/2,arr);
    recursion(x_start + size/2,y_start + size/2,size/2,arr);
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    int n = arr.size();
    recursion(0,0,n,arr);
    answer.push_back(zero);
    answer.push_back(one);
    return answer;
}
