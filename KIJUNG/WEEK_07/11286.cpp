#include <iostream>
#include <queue>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N, tmp;
priority_queue<int> q;
priority_queue<int> minusQ;


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;

    FOR(i,0,N){
        cin >> tmp;
        if(tmp == 0){
            if(q.empty() && minusQ.empty()){
                cout << 0 << "\n";
            }
            else if (!q.empty() && minusQ.empty()){
                cout << -q.top() << "\n";
                q.pop();
            }
            else if (q.empty() && !minusQ.empty()){
                cout << minusQ.top() << "\n";
                minusQ.pop();
            }
            else {
                if(q.top() == minusQ.top()){
                    cout << minusQ.top() << "\n";
                    minusQ.pop();
                }
                else{
                    if(q.top() < minusQ.top()){
                        cout << minusQ.top() << "\n";
                        minusQ.pop();
                    }
                    else {
                        cout << -q.top() << "\n";
                        q.pop();
                    }
                }
            }
        }
        else if(tmp>0) {
            q.push(-tmp);
        }
        else {
            minusQ.push(tmp);
        }
    }
    return 0;
}