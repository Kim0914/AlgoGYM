#include <iostream>
#include <queue>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N, tmp, minTop, maxTop;
priority_queue<int> maxHeap;
priority_queue<int> minHeap;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    FOR(i,0,N){
        cin >> tmp;
        if(i==0) {
            maxHeap.push(tmp);
            cout << maxHeap.top() << "\n";
            continue;
        }

        if(maxHeap.size()>minHeap.size()) minHeap.push(-tmp);
        else maxHeap.push(tmp);
        
        minTop = -minHeap.top();
        maxTop = maxHeap.top();
        
        if(maxTop > minTop){
            minHeap.pop();
            maxHeap.pop();
            maxHeap.push(minTop);
            minHeap.push(-maxTop);
        }
        
        cout << maxHeap.top() << "\n";
    }

    return 0;
}