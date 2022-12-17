#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    string s; cin >> s;
    ll mod = 9007199254740881;
    vector<vector<ll>>v;
    unordered_map<ll,int>m;
    for(int i=0;i<s.length();i++){
        ll sum = 0;
        ll minyo = 0;
        ll D = 256;
        for(int j=i;j<s.length();j++){
            minyo = (minyo*D+s[j]) % mod;
            if(m.find(minyo) == m.end())
                v.push_back({i, j});
            m[minyo] = 1;
        }
    }
    cout<<v.size()<<endl;
}