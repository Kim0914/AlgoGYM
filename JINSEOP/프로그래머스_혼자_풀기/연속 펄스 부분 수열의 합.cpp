#include <string>
#include <vector>
using namespace std;

vector<int> origin_vector;
vector<int> reverse_vector;
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
    for (int i = 0; i < sequence.size(); i++) {
        long long sum = 0;
        long long rev_sum = 0;

        for (int j = i; j < sequence.size(); j++) {
            sum += origin_vector[j];
            rev_sum += reverse_vector[j];

            if (sum > answer || rev_sum > answer)
                answer = sum > rev_sum ? sum : rev_sum;
        }
    }
}

long long solution(vector<int> sequence) {
    long long answer = 0;

    original_pulse(sequence);
    calculate_partial_sum(sequence, answer);

    return answer;
}
