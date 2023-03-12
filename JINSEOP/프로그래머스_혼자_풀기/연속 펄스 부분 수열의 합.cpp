#include <string>
#include <vector>
using namespace std;

vector<long long> origin_vector;
vector<long long> reverse_vector;
long long DP[500000];
void original_pulse(vector<int> sequence) {
    for (int i = 0; i < sequence.size(); i++) {
        if (i % 2 == 0) {
            origin_vector.push_back(sequence[i]);
            reverse_vector.push_back(sequence[i] * -1);
        }
        else {
            origin_vector.push_back(sequence[i] * -1);
            reverse_vector.push_back(sequence[i]);
        }
    }
}

void calculate_partial_sum(vector<int> sequence, long long& answer) {
    DP[0] = origin_vector[0];

    for (int i = 1; i < origin_vector.size(); i++) {
        DP[i] = max(DP[i - 1] + origin_vector[i], origin_vector[i]);
        answer = max(answer, DP[i]);
    }

    DP[0] = reverse_vector[0];
    for (int i = 1; i < reverse_vector.size(); i++) {
        DP[i] = max(DP[i - 1] + reverse_vector[i], reverse_vector[i]);
        answer = max(answer, DP[i]);
    }
}

long long solution(vector<int> sequence) {
    long long answer = 0;

    if(sequence.size() == 1){
        if((sequence[0] * -1) > 0)
            return sequence[0] * -1;
        else 
            return sequence[0];
    }
    else{
        original_pulse(sequence);
        calculate_partial_sum(sequence, answer);
    }

    return answer;
}

// DP로는 O(N)이 불가능할거라고 생각하고 있었는데, 가능했다.
