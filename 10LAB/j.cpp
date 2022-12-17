#include<bits/stdc++.h>
using namespace std;

vector<list<int> > adj;
vector<bool> visited;

int count(int a){
    int cnt = 0;
    deque<int> deq;
    deq.push_back(a);
    visited[a] = true;
    while(!deq.empty()){
        int del = deq.size();
        for(int i = 0; i < del; i++){
            int sts = deq.front();
            deq.pop_front();
            for(auto a : adj[sts]){
                if(visited[a]){
                    continue;
                }
                if(adj[a].size() > adj[sts].size()){
                    cnt++;
                }
                deq.push_back(a);
                visited[a] = true;
            }
        }
    }
    return cnt;
}

int main(){
    int n , m, u, v, ans = 0;
    cin >> n >> m;
    adj.resize(n);
    visited.resize(n);
    while(m--){
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            ans += count(i);
            ans++;
        }
    }
    cout << ans;
    return 0;
}