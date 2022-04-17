#include <iostream>
#include <vector>
#include <algorithm>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

long long N, K;
long long ans;
vector<long long> v;

void solve(long long n, int idx, bool asc){
    if(asc){
        FOR(i,1,idx+1){
            v.push_back(i*(idx+1-i));
        }
    }
    else{   
        FOR(i,N-idx+1,N+1){
            v.push_back(i*(2*N+1-idx-i));
        }

    }
    sort(v.begin(), v.end());
  
    cout << v.at(K-n);
}

int main(void){
    cin >> N >> K;

    FOR(i,1,N+1){
        if(ans+i>K) {
            solve(ans, i, true);
            break;    
        }
        ans += i;
        if(i==N){
            for(int j = N-1;j>0;j--){
                if(ans+j> K ) {
                    solve(ans, j, false);
                    break;        
                }
                ans+=j;
            }
        }
    }

    return 0;
}