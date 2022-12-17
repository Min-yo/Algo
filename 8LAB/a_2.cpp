#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long

string get_hash(string s) {
    const int p = 11;
    ll hash = 0, powr = 1;
    for(ll i = 0; i < s.size(); i++) {
        hash = (hash + ((s[i] - 47 ) * powr)%1000000007) % 1000000007;
        powr = (powr * p) % 1000000007;
    }
    return to_string(hash);
}
int main(){
    ll n; cin >> n;
    vector<string> v;
    for(int i = 0;i < 2 * n;i++){
        string s; 
        cin >> s;
        v.push_back(s);
    }
    
    for(auto i : v){//vector<string>::iterator it = find(v.begin(), v.end(), get_hash(i));
        string hashed = get_hash(i);
        if(find(v.begin(), v.end(), hashed)!=v.end()){//string s1 = "Hash of string \"" + i + "\" is " + get_hash(i) +"\n";
            //cout << s1;
            printf("Hash of string \"%s\" is %s\n", i.c_str(), hashed.c_str());
        }
    }  
    
    return 0;
}