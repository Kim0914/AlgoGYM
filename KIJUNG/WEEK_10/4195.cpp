#include <iostream>
#include <algorithm>
#include <map>
#include <string>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int T, F, parent[200002], counter[200002];

int set_find(int x){
    if(parent[x] == x) return x;
    else return parent[x] = set_find(parent[x]);
}

int set_union(int x, int y){
    int px = set_find(x);
    int py = set_find(y);

    if(set_find(px) != set_find(py)){
        parent[py] = px;
        counter[px] += counter[py];
        counter[py] = 1;
    }
    return counter[px];
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;

    while(T--){
        map<string, int> M;
        int cnt = 1;
        int idx1, idx2;
        string str1, str2;

        FOR(i,0,200002) parent[i] = i;
        fill(counter, counter+200002, 1);
        cin >> F;
        while(F--){
            cin >> str1 >> str2;
            if(M[str1] == 0) M[str1]=cnt++;
            idx1 = M[str1];
            if(M[str2] == 0) M[str2]=cnt++;
            idx2 = M[str2];
            
            cout << set_union(idx1, idx2) << "\n";
        }
    }
    
    return 0;
}