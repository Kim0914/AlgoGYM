#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> multiplicate_matrix(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    for (int outer = 0; outer < arr1.size(); outer++) {
        vector<int> temp;

        for (int i = 0; i < arr2[0].size(); i++) {
            int sum = 0;
            for (int j = 0; j < arr1[0].size(); j++) {
                sum += arr1[outer][j] * arr2[j][i];
            }
            temp.push_back(sum);
        }
        answer.push_back(temp);
    }
    
    return answer;
}

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    answer = multiplicate_matrix(arr1, arr2);
    return answer;
}
