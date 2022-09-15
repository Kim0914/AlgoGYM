#include <string>
#include <vector>
using namespace std;

vector<vector<int>> add_matrix(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    for (int i = 0; i < arr1.size(); i++) {
        vector<int> temp;
        for (int j = 0; j < arr1[i].size(); j++)
            temp.push_back(arr1[i][j] + arr2[i][j]);

        answer.push_back(temp);
    }

    return answer;
}

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    answer = add_matrix(arr1, arr2);
    return answer;
}
