#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    char a;
    vector<char> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    cin >> a;
    bool flag = true;
    for(int i = 0; i < n; i++){
        //cout << int(v[i]) << " " << int(a)<< endl;;
        if(char(v[i]) > char(a)){
            cout << v[i];
            flag = false;
            break;
        }
       
    }
    if(flag) cout << v[0];
    return 0;
}