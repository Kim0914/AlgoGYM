#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N, danji, map[26][26], visited[26][26];
vector<int> danjies;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
string str;

void dfs(int y, int x){
    visited[y][x] = 1;
    danji++;
    FOR(l,0,4){
        int ny = y + dy[l];
        int nx = x + dx[l];
        if(ny<1 || nx<1 || ny>N || nx>N) continue;
        if(map[ny][nx] == 1 && visited[ny][nx] == 0){
            dfs(ny,nx);
        }
    }
}

int main(void){
    cin >> N;
    FOR(i,1,N+1){
        cin >> str;
        FOR(j,0,N){
            map[i][j+1] = str[j] - 48;
        }
    }

    FOR(i,1,N+1){
        FOR(j,1,N+1){
            if(map[i][j] == 1 && visited[i][j] == 0){
                danji = 0;
                dfs(i,j);
                danjies.push_back(danji);
            }
        }
    }

    sort(danjies.begin(), danjies.end());

    cout << danjies.size() << "\n";
    FOR(i,0,danjies.size()){
        cout << danjies[i] << "\n";
    }

    return 0;
}