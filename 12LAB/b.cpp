#include <bits/stdc++.h>  
using namespace std;  
 
long long INF = 1000000000;  
vector<pair<long long,long long>> g[200000];  
vector<long long> d(200000, INF);  
long long n,m;  
 
long long dijkstra(long long s, long long end){  
    d.clear();  
    for(long long i=0;i<200000;i++){  
        d[i] = INF;  
    }  
    d[s] = 0;  
    set< pair<long long,long long> > q;  
    q.insert(make_pair(d[s],s));  
    while(!q.empty()){  
        long long v = q.begin()->second;  
        q.erase(q.begin());  
        for(long long j = 0;j<g[v].size();j++){  
            long long to = g[v][j].first;  
            long long len = g[v][j].second;  
            if(d[v] + len < d[to]){  
                q.erase(make_pair(d[to], to));  
                d[to] = d[v] + len;  
                q.insert(make_pair(d[to], to));  
            }  
        }  
    }  
    return d[end];  
}  
 
 
 
int main(){ long long a,b,c,q,w,e,r; 
    cin >> n >> m;  
    for (long long i = 0; i < m; i++){  
        cin >> a >> b >> c;  
        g[a].push_back({b,c});  
        g[b].push_back({a,c});  
    }  
    cin >> q >> w >> e >> r;  
    a = dijkstra(q,w) + dijkstra(w,e) + dijkstra(e,r);  
    b = dijkstra(q,e) + dijkstra(e,w) + dijkstra(w,r) ;  
    if(min(a,b) <= INF){  
        cout << min(a,b);  
    }else{  
        cout << -1;  
    }  
    return 0;  
}