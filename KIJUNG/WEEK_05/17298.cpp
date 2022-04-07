#include <iostream>
#include <stack>

using namespace std;

int N;
int nums[1000001];
int RbigN[1000001];
stack<int> s;

int main(void){
    cin >> N;

    for(int i=1; i<N+1; i++){
        cin >> nums[i];
    }
    
    for(int i=N; i>0; i--){
        while (!s.empty() && s.top() <= nums[i])
			s.pop();

		if (s.empty()) RbigN[i] = -1;
		else RbigN[i] = s.top();

		s.push(nums[i]);
    }

    for(int i=1; i<N+1; i++){
        cout << RbigN[i] << " ";
    }

    return 0;
}