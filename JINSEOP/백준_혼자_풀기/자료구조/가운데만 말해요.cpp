#include <iostream>
#include <queue>
using namespace std;

int num = 0, digit = 0;
priority_queue<int> max_heap;
priority_queue<int, vector<int>, greater<>> min_heap;
void optimize() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    optimize();

    cin >> num;
    for(int i = 0; i < num; i++){
        cin >> digit;

        if (max_heap.size() == min_heap.size())
            max_heap.push(digit);
        // 두 큐의 크기가 같다는 것은 짝수개라는 의미.
        else
            min_heap.push(digit);

        if (!max_heap.empty() && !min_heap.empty()) {
        // 두 큐가 비어있지 않고 (처음 2단계가 아님을 의미)
            if (max_heap.top() > min_heap.top()) {
            // 작은 것들 중 가장 큰 값 > 큰 것들 중 가장 작은 값
                int max_val = max_heap.top(), min_val = min_heap.top();
            // 이는 둘의 위치가 바뀌어야 함을 의미한다.
                max_heap.pop(); min_heap.pop();
                max_heap.push(min_val); min_heap.push(max_val);
            }
        }

        cout << max_heap.top() << '\n';
    }
    return 0;
}
