#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<float, int> classifier;
long long solution(vector<int> weights) {
    long long answer = 0;

    for (float w : weights) {
        answer += classifier[w] + classifier[w * 2] + classifier[float(w / 2)] + classifier[float((w * 2) / 3)]
            + classifier[float((w * 3) / 2)] + classifier[float((w * 3) / 4)] + classifier[float((w * 4) / 3)];

        classifier[w] += 1;
    }

    return answer;
}

int main() {
    vector<int> weights = { 100,180,360,100,270 };
    solution(weights);
}
