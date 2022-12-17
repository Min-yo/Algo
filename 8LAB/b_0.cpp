#include <bits/stdc++.h>
using namespace std;
#define ll long long

map <int, int> m;
int ans = 0;

ll getHash(string & s1) {
    ll sum = 0; 
    ll powr = 1;
    for (int i = 0; i < s1.size(); i++) {

        ll cur = (s1[i] - 96) * powr % 1000000000;
        sum = (sum + cur) % 1000000000;
        powr = (powr * 31) % 1000000000;

    }

    return sum; 
}
vector<ll> patHash(string & s1) { 
    vector<ll> rashsh(s1.size()); 
    ll powr = 1;
    for (int i = 0; i < s1.size(); i++) {
        rashsh[i] = (s1[i] - 96) * powr % 1000000000;
        if (i) {
            rashsh[i] = (rashsh[i] + rashsh[i - 1]) % 1000000000;
        }
        powr = (powr * 31) % 1000000000;
    }
    return rashsh;
}




void rbnKarp(string & s1, string & s2) { 
    if (s2.size() > s1.size())
        return;
    ll hsh = getHash(s2);
    vector<ll> nash = patHash(s1);
    for (int i = 0; i < s1.size() - s2.size() + 1; i++) {
        ll trashsh = nash[i + s2.size() - 1];
        if (i != 0) 
            trashsh -= nash[i - 1];
        if (trashsh < 0) 
            trashsh += 1000000000;
        if (i != 0) 
            hsh = (hsh * 31) % 1000000000;
        if (hsh == trashsh){
            if (m.find(i) != m.end()) {
                ans++;
            }
            m[i] = 1;
        }
    }

}


int main() {
    string s1, s2, pattern;
    cin >> s1 >> s2 >> pattern;

    rbnKarp(s1, pattern); 
    rbnKarp(s2, pattern); 

    cout << ans << endl;
}