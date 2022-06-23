#include <string>
#include <vector>
#include <algorithm>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    bool relation[101][101] = {false,};

    for(vector<int> result: results){
        relation[result[0]][result[1]] = true;
    }

    FOR(k,1,n+1){
        FOR(i,1,n+1){
            FOR(j,1,n+1){
                if(relation[i][k] && relation[k][j]) relation[i][j] = true;
            }
        }
    }

    FOR(i,1,n+1){
        answer++;
        FOR(j,1,n+1){
            if(!relation[i][j] && !relation[j][i] && i!=j) {
                answer--;
                break;
            }
        }
    }

    return answer;
}