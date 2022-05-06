#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N, nums[1000001], dp[1000001];
vector<int> lis;
stack<int> s;

int main(void){
    cin >> N;

    FOR(i,0,N){
        cin >> nums[i];
        dp[i] = 1;
    }

    lis.push_back(nums[0]);

    FOR(i,1,N){
        if(nums[i]>lis.back()) {
            lis.push_back(nums[i]);
            dp[i] = lis.size();
        }
        else{
            vector<int> :: iterator j = lower_bound(lis.begin(), lis.end(), nums[i]);
            *j = nums[i];
            dp[i] = j-lis.begin()+1;
        }
    }

    int len = lis.size();
    cout << len << "\n";
    
    for(int i = N-1;i>=0;i--){
        if(dp[i] == len) {
            s.push(nums[i]);
            len--;
        }
    }

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}

// cnt를 저장하는 dp를 추가로 활용!!
// 왜냐하면 lis 값을 치환하는 방식은 길이는 lis와 같지만 실제 lis가 아니기 때문!
// 따라서, 같거나 큰 원소가 처음으로 나오는 인덱스가 있는 경우 해당 dp에 그 인덱스를 저장해준다.
// dp 배열의 뒤부터 탐색하면서 인덱스를 역순으로 탐색하면 lis완성이다!!!