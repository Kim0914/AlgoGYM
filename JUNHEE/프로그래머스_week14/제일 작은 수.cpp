#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int min = *min_element(arr.begin(), arr.end());
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == min) continue;
        answer.push_back(arr[i]);
    }
    if(answer.empty()) answer.push_back(-1);
    return answer;
}
