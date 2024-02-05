#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

unordered_map<int, int> counter;
vector<int> num_list;
int solution(vector<int> a) {
    int answer = 0;
    
    vector<bool> check(0, a.size());
    for (int i = 0; i < a.size(); i++) {
        if (counter[a[i]] == 0)
            num_list.push_back(a[i]);
        // 등록되지 않은 수는 벡터에 등록
        counter[a[i]]++; // 수열 내에 수가 나오는 횟수를 세어준다.
    }

    for (int i = 0; i < num_list.size(); i++) {
        // 등장하는 수를 모두 순회하며 스타 수열을 만들어본다.
        if (answer >= counter[num_list[i]])
            continue;
        // 등장 횟수가 현재 정답보다 같거나 작으면
        // 탐색해봐야 길이가 같거나 작을 수 밖에 없다.
        // 따라서 그냥 패스!

        int cnt = 0; // 스타 수열 길이
        for (int j = 0; j < a.size() - 1; j++) {
            if (a[j] != num_list[i] && a[j + 1] != num_list[i])
                continue;
            // 둘 다 대상 수가 아니면 통과
            if (a[j] == a[j + 1])
                continue;
            // 둘 다 대상 수로 같으면 통과
            
            cnt++;
            j++; // 만약 스타 수열로 채택했으면 2칸을 넘어감
            // j + 1은 이미 스타 수열로 채택됐기 때문!
        }

        answer = max(answer, cnt);
    }

    return answer * 2;
}

int main() {
    solution({ 5,2,3,3,5,3 });
	return 0;
}
