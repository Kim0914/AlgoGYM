#include <string>
#include <vector>
using namespace std;

vector<int> run_progress(vector<int>& progresses, vector<int> speeds) {
    int p_ptr = 0;
    vector<int> res;
    
    while (true) {
        int dep_cnt = 0;
        for (int i = p_ptr; i < progresses.size(); i++) {
            progresses[i] += speeds[i];
            if (progresses[p_ptr] >= 100) {
                dep_cnt++;
                p_ptr++;
            }
        }
        
        if(dep_cnt != 0) res.push_back(dep_cnt);
        if (p_ptr == progresses.size()) break;
    }

    return res;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    answer = run_progress(progresses, speeds);
    return answer;
}
