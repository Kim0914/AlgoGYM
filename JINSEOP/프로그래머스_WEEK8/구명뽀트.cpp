#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

deque<int> classifier;
void init_queue(vector<int> people) {
    sort(people.begin(), people.end(), greater<>());

    for (int i = 0; i < people.size(); i++) {
        classifier.push_back(people[i]);
    }
}

void next_ship(int& answer, int& person, int& sum) {
    answer++; 
    person = 0; sum = 0;
}

int solution(vector<int> people, int limit) {
    int answer = 0, sum = 0, person = 0;

    init_queue(people);

    while (!classifier.empty()) {
        sum += classifier.front();
        classifier.pop_front(); person++;

        if (classifier.empty()) {
            answer++;
            break;
        }

        sum += classifier.back(); person++;

        if (sum > limit) {
            next_ship(answer, person, sum);
            continue;
        }
        if(person == 2) {
            classifier.pop_back();
            next_ship(answer, person, sum);
        }
    }

    return answer;
}
