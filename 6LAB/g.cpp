#include <bits/stdc++.h> 
using namespace std; 
 
int main(){ 
    int q; 
    cin >> q; 
    map<string, string> m; 
    map<string, string>::iterator it; 
    for(int i = 0; i < q; i++){ 
        string old, neww; 
        cin >> old >> neww; 
        m[old] = neww; 
 
        for(it = m.begin(); it != m.end(); it++){ 
            if(it->second == old){ 
                it->second = neww; 
                m.erase(old);
            } 
        } 
    } 
 
    cout << m.size() << endl; 
    for(it = m.begin(); it != m.end(); it++){ 
        cout << it->first << " " << it->second << endl; 
    } 
    return 0; 
}