#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    
    vector<int> nodeEdge[20001];
    queue<pair<int,int> > q;
    int visited[20001] = {0, };

    for(vector<int> e: edge){
        nodeEdge[e[0]].push_back(e[1]);
        nodeEdge[e[1]].push_back(e[0]);
    }
    
    q.push(make_pair(1,1));
    while(!q.empty()){
        int cnt = q.front().first;
        int cur = q.front().second;
        q.pop();
        
        if(visited[cur] != 0) continue;
        visited[cur] = cnt;
        for(int node: nodeEdge[cur]) q.push(make_pair(cnt+1,node));
    }
    
    int maxLen = *max_element(visited, visited+20001);
    
    return count(visited,visited+20001,maxLen);
}