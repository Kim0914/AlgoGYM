#include <vector>
#include <algorithm>

#define INF 200000000
#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 1000000000;

    int edge[201][201];
    fill(&edge[0][0], &edge[200][201], INF);

    for(vector<int> fare: fares){
        edge[fare[0]][fare[1]] = fare[2];
        edge[fare[1]][fare[0]] = fare[2];
    }

    FOR(k,1,n+1){
        FOR(i,1,n+1){
            FOR(j,1,n+1){
                if(edge[i][k] != INF && edge[k][j] != INF){
                    edge[i][j] = min(edge[i][k]+edge[k][j], edge[i][j]);
                }
            }
        }
    }

    FOR(i,1,n+1){
        edge[i][i] = 0;
        answer = min(edge[s][i]+edge[a][i]+edge[b][i],answer);
    }
    
    return answer;
}