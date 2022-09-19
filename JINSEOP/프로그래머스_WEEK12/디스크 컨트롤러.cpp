#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct cmp {
    bool operator()(vector<int>& a, vector<int>& b) {
        return a[1] > b[1];
    }
};

priority_queue<vector<int>, vector<vector<int>>, cmp> job_classifier;
vector<int> task_time;
void reduce_avg_time(vector<vector<int>> jobs) {
    int timer = 0, task_cnt = 0;

    while (task_cnt < jobs.size() || !job_classifier.empty()){
        if (task_cnt < jobs.size() && jobs[task_cnt][0] <= timer) {
            job_classifier.push(jobs[task_cnt]);
            task_cnt++; continue;
        }

        if (!job_classifier.empty()) {
            timer += job_classifier.top()[1];
            task_time.push_back(timer - job_classifier.top()[0]);
            job_classifier.pop();
        }

        else timer = jobs[task_cnt][0];
    }
}

int calc_avg_time() {
    int sum = 0;

    for (int i : task_time)
        sum += i;

    return (sum / task_time.size());
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;

    sort(jobs.begin(), jobs.end());
    reduce_avg_time(jobs);
    answer = calc_avg_time();

    return answer;
}
