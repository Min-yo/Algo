#include <bits/stdc++.h>
using namespace std; 
int n, m, v; 
vector<pair<pair<int, int>, int>> e; 
bool flag = false; 
void solve() { 
    vector<int> vec (n, 1000000000); 
    vec[v] = 0; 
    vector<int> p (n, -1); 
    int a; 
    for (int i=0; i<n; ++i) { 
        a = -1; 
        for (int j=0; j<n * n; ++j) 
            if (vec[e[j].first.first] < 1000000000) 
                if (vec[e[j].first.second] > vec[e[j].first.first] + e[j].second) { 
                    vec[e[j].first.second] = max (-1000000000, vec[e[j].first.first] + e[j].second); 
                    p[e[j].first.second] = e[j].first.first; 
                    a = e[j].first.second; 
                } 
    } 
 
    if (a == -1) 
        flag = false; 
    else { 
        int b = a; 
        for (int i=0; i<n; ++i) 
            b = p[b]; 
 
        vector<int> path; 
        for (int cur=b; ; cur=p[cur]) { 
            path.push_back (cur); 
            if (cur == b && path.size() > 1)  break; 
        } 
        reverse (path.begin(), path.end()); 
 
        cout << "YES" << endl; 
        cout << path.size() << endl; 
        for (size_t i=0; i<path.size(); ++i) 
            cout << path[i] + 1 << ' '; 
        cout << endl; 
        flag = true; 
    } 
} 
 
int main(){ 
    cin >> n; 
    vector<int> vec(n, 1000000000); 
    for (int i = 0; i < n; i ++){ 
        for (int j = 0; j < n; j ++){ 
            pair<pair<int, int>, int> cur; 
            cin >> cur.second; 
            cur.first.first = i; cur.first. second = j; 
            e.push_back(cur); 
        } 
    } 
    for (int i = 0; i < n; i ++){ 
        v = i; 
        solve(); 
        if (flag) break; 
    } 
    if (!flag) cout << "NO" << endl; 
}