#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1000000000

using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 1;
    int city[51][51];
    fill(&city[0][0], &city[50][51], INF);
    for(vector<int> v: road){
        city[v[0]][v[1]] = min(v[2],city[v[0]][v[1]]);
        city[v[1]][v[0]] = min(v[2],city[v[1]][v[0]]);
    } 

    for(int k=1;k<N+1;k++){
        for(int i=1;i<N+1;i++){
            for(int j=1;j<N+1;j++){
                if(city[i][k] != INF && city[k][j] != INF){
                    city[i][j] = min(city[i][j], city[i][k] + city[k][j]);
                }
            }
        }
    }

    for(int i=2;i<N+1;i++){
        if(city[1][i] <= K) answer++;
    }

    return answer;
}