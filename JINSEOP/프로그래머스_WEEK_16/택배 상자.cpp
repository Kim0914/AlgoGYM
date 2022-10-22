#include <string>
#include <vector>
#include <stack>
using namespace std;

stack<int> support_container;
int count_loadable_box(vector<int> order) {
    int curr_box = 1, iter = 0, cnt = 0;
    int size = order.size();

    while (true) {
        if (iter >= size) break;
        if (curr_box > size + 1) break;

        if (order[iter] == curr_box) {
            iter++;
            curr_box++;
            cnt++;
        }
        else {
            if (!support_container.empty()) {
                if (support_container.top() == order[iter]) {
                    iter++;
                    cnt++;
                    support_container.pop();
                    continue;
                }
            }

            support_container.push(curr_box);
            curr_box++;
        }
    }
    
    return cnt;
}

int solution(vector<int> order) {
    int answer = 0;
    
    answer = count_loadable_box(order);
    return answer;
}
