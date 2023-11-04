#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int num = 0, partit = 0, height = 0, answer = 0;
vector<int> students;
int main(){
	cin >> num >> partit;
	for (int i = 0; i < num; i++) {
		cin >> height;
		students.push_back(height);
	}

	vector<int> diff_vector;
	for (int i = 1; i < num; i++) {
		int diff = abs(students[i] - students[i - 1]);
		diff_vector.push_back(diff);
		// 각 구간의 차이를 모두 저장한다.
	}

	sort(diff_vector.begin(), diff_vector.end());
	// 각 차이들을 오름차순으로 정렬한다.
	// 왜? 차이가 작은 놈들을 우선으로 뽑을 것이기 때문!

	for (int i = 0; i < num - partit; i++)
		answer += diff_vector[i];
	cout << answer;
	// 가장 최소 비용을 갖는 경우는 언제?
	// 2 5 6 7 9 를 2조로 나눌 때를 한 번 생각해보자.
	// (2) (5, 6, 7, 9)가 아마 최소일 것이다.
	// 왜일까? 모든 조 사이의 차이를 구해보면, 3 1 2 2이다.
	// 이를 오름차순 정렬하면 1 1 2 3이 되는데..
	// 이 때, 이 문제를 푸는 핵심은 키 차이를 큰 곳부터 (K-1)개 제외하는 것이다.
	// 그 말은? 해당 구간에 벽을 설치한다는 의미이다! 
	// 우리는 K개의 조를 만들기 위해서 K-1개의 벽이 필요하기 때문에, K-1개를 제외하는 것이다.

	// 따라서 1개를 제외, 앞에서부터 3개만 선택하면 된다. (N - 1) - (K - 1) = N - K
	// 1, 1, 2를 선택하는 것인데 이는 (5-6-7-9)를 골라 4가 되고, 2는 혼자 떨어트려 차이를 더하지 않은 것이다.

	return 0;
}
