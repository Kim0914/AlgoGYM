#include <iostream>
#include <vector>
#include <algorithm>

#define FOR(i,a,b) for(int i =a;i<b;i++)

using namespace std;

int N;
int nums[100001];
vector<int> s;

void sol(){
    int cnt = 1;
    
    FOR(i,1,N+1){
        if(s.empty()) {
            s.push_back(cnt++);
            cout << "+\n";
        }
        while(s.back() < nums[i]){
            s.push_back(cnt++);
            cout << "+\n";
        }
        while(s.back() >= nums[i]){
            s.pop_back();
            cout << "-\n";
        }
    }
}

bool possible(){
    int cnt = 1;
    FOR(i,1,N+1){
        if(s.empty()) {
            if(cnt>nums[i]) return false;
            s.push_back(cnt++);
        }
        while(s.back() < nums[i]){
            if(cnt>nums[i]) return false;
            s.push_back(cnt++);
        }
        while(s.back() >= nums[i]){
            s.pop_back();
        }
    }
    return true;
}

int main(void){
    cin >> N;

    FOR(i,1,N+1){
        cin >> nums[i];
    }

    if(possible()) {
        s.clear();
        sol();
    }
    else cout << "NO\n";

    return 0;
}