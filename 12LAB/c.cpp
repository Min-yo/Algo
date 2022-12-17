#include <bits/stdc++.h> 
using namespace std;  
 
vector<int>roads[400];  
vector<int>airs[400];  
int ar[400][400];  
 
int main(){  
    int n,m;  
    cin >> n >> m;  
    for(int i=0;i<m;i++){  
        int a,b;  
        cin >> a >> b;  
        a--;  
        b--;  
        roads[a].push_back(b);  
        roads[b].push_back(a);  
        ar[a][b] = 1;  
        ar[b][a] = 1;  
    }  
    for (int i = 0; i < n; i ++){  
        for (int j = 0; j < n; j ++){  
            if (ar[i][j] == 0 && i != j){  
                airs[i].push_back(j);  
            }  
        }  
    }  
    deque<int>dec1, dec2;  
    vector<int>d1(n+1), d2(n+1);  
    vector<bool>visited1(n+1), visited2(n+1);  
    dec1.push_back(0);  dec2.push_back(0);
    visited1[0] = true;  visited2[0] = true;  
    while(!dec1.empty()){  
        int v = dec1.front();  
        dec1.pop_front();  
        for(int i=0;i<roads[v].size();i++){  
            int to = roads[v][i];  
            if(!visited1[to]){  
                visited1[to] = true;  
                dec1.push_back(to);  
                d1[to] = d1[v]+1;  
            }  
        }  
    }  
    while(!dec2.empty()){  
        int v = dec2.front();  
        dec2.pop_front();  
        for(int i=0;i<airs[v].size();i++){  
            int to = airs[v][i];  
            if(!visited2[to]){  
                visited2[to] = true;  
                dec2.push_back(to);  
                d2[to] = d2[v]+1;  
            }  
        }  
    }  
    if (!visited1[n-1] || !visited2[n-1]) cout << -1;  
    else cout << max(d1[n-1], d2[n-1]);
}