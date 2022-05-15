#include <iostream>
#include <algorithm>
#include <map>
#include <string>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int T, F, parent[100002];
map<string, int> M;

int set_find(int x){
    if(parent[x] == x) return x;
    else return parent[x] = set_find(parent[x]);
}

void set_union(int x, int y){
    int px = set_find(x);
    int py = set_find(y);

    if(px<py) parent[py] = px;
    else parent[px] = py;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;

    FOR(i,0,T){
        int idx = 1;
        cin >> F;
        FOR(i,0,F){
            int cnt = 0;
            string str1, str2;
            cin >> str1 >> str2;
            if(M.lower_bound(str1) == M.end()) {
                M[str1]=idx;
                parent[idx] = idx;
                idx++;
            }
            if(M.lower_bound(str2) == M.end()) {
                M[str2]=idx;
                parent[idx] = idx;
                idx++;
            }
            
            // cout << M[str1] << " " << M[str2] << "\n";

            set_union(M[str1], M[str2]);
            // FOR(j,1,idx){
            //     cout << parent[j] << " ";
            // }
            // cout << "\n";
            
            int tp = set_find(M[str1]);
            FOR(j,1,idx){
                if(set_find(j) == tp) cnt++;
            }
            cout << cnt << "\n";
        }
        M.clear();
        fill(parent, parent+100002, 0);
    }
    

    return 0;
}