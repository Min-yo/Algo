#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > g;
vector<bool> visited;
void dfs (int v){
    visited[v] = true;
    cout << v << " ";
    for(int i = 0; i < g[v].size(); i++){
        int u = g[v][i];
        if (!visited[u]) dfs(u);
    }
}

void bfs(int v){
    queue<int> q;
    q.push(v);
    visited[v] = true;
    while(!q.empty()){
        int cur = q.front();
        cout << cur << " ";
        for(int i = 0; i < g[cur].size(); i++){
            int u = g[cur][i];
            if (!visited[u]){
                visited[u] = true;
                q.push(u);
            }
        }
        q.pop();
    }
}
