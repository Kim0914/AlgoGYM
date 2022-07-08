#include <vector>
#include <algorithm>

using namespace std;
/**
 * @brief dfs로 풀었다가 시간초과가 나서 플로이드 와셜알고리즘으로 최단거리를 구해 가지치기를 했지만 역시 시간초과.
    에초에 노드가 200개 + 중복 노드 혀용이라서 안되는 알고리즘이었다.
 * 
 */
int mindist[201][201];
vector<int> edge_list2[201];
vector<int> path;
int answer;

void dfs(int cur, int cnt, int k, vector<int> &gps_log){
    if(cnt == k) {
        if(cur == gps_log[k-1]){
            int minfix=0;
            for(int i=0;i<gps_log.size();i++){
                if(gps_log[i]!=path[i]) minfix++;
            }
            answer = min(answer, minfix);
        }
        return;
    }

    if(mindist[cur][gps_log[k-1]] > k-cnt) return;

    for(int edge: edge_list2[cur]){
        path.push_back(edge);
        dfs(edge, cnt+1, k, gps_log);
        path.pop_back();
    }
}

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    answer = k-1;
    path.clear()
    for(int i=0;i<201;i++) edge_list2[i].clear();

    fill(&mindist[1][1], &mindist[200][201], 10000);

    for(vector<int> edge: edge_list){
        edge_list2[edge[0]].push_back(edge[1]);
        edge_list2[edge[1]].push_back(edge[0]);
        //플로이드 와셜
        mindist[edge[0]][edge[1]] = 1;
        mindist[edge[1]][edge[0]] = 1;
    }

    for(int i=1;i<n+1;i++){
        if(!edge_list2[i].empty()) {
            edge_list2[i].push_back(i);
            mindist[i][i] = 1;
        }
    }

    for(int k=1;k<n+1;k++){
        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                if(mindist[i][k]!=10000 && mindist[k][j]!=10000){
                    mindist[i][j] = min(mindist[i][k] + mindist[k][j], mindist[i][j]);
                }
            }
        }
    }

    path.push_back(gps_log[0]);
    dfs(gps_log[0], 1, k, gps_log);

    if(answer==k-1) return -1;
    return answer;
}