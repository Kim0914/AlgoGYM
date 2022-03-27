#include <iostream>
#include <vector>
#include <algorithm>

#define FOR(i,a,b) for(int i = a; i<b; i++)

using namespace std;

int N;
int tmp1,tmp2;
vector<int> tmpVec;
vector<vector<int> > con;
int M = -1;

void bt(int start, int cnt, int cur){
    M = max(M, cnt);
    FOR(i,cur,N){
        if(con[i][0] >= start){
            bt(con[i][1], cnt+1, i+1);
        }
    }
}

int main(void){ 
    cin >> N;
    FOR(i,1,N+1){
        cin >> tmp1 >> tmp2;
        tmpVec.push_back(tmp1);
        tmpVec.push_back(tmp2);
        con.push_back(tmpVec);
        tmpVec.clear();
    }

    sort(con.begin(),con.end());

    FOR(i,0,N){
        cout << con[i][0] << " " << con[i][1] << "\n";
    }

    bt(0,0,0);

    cout << M;

    return 0;
}

//시간 초과 ... 최악 O(N!) 알고리즘ㅋㅋ 될리가 없다