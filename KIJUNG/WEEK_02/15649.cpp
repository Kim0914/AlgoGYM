#include <iostream>
#include <vector>
#include <algorithm>

#define FOR(i,a,b) for(int i =a;i<b;i++)

using namespace std;

int N, M;

vector<int> num;
vector<int> visited(8);

void recur(){
    if(num.size() == M){
        FOR(i,0,M){
            cout << num[i] + 1<<" ";
        }
        cout << "\n";
    }

    FOR(i,0,N){
        if(visited[i] == 0){
            visited[i] = 1;
            num.push_back(i);
            recur();
            num.pop_back();
            visited[i] = 0;
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N >> M;

    recur();
    return 0;
}