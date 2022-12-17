#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long


string get_hash(string s) {
    const int p = 11;
    ll hash = 0, powr = 1;
    for(ll i = 0; i < s.size(); i++) {
        hash = (hash + ((s[i]) - 47 ) * powr) % 1000000007;
        powr = (powr * p) % 1000000007;
    }
    return to_string(hash);
}
int main(){
    ll n; cin >> n;
    string s;
    vector<string> str(2*n);
    vector<pair<string, string> > ans;
    for(ll i = 0; i < 2*n ; i++){
        cin >> str[i];
    }
    while(ans.size() != n){
        for(ll i = 0; i < 2*n; i++){
            vector<string>::iterator it = find(str.begin(), str.end(), get_hash(str[i]));
          
            if(it!=str.end()){//cout << str[i] << " " << get_hash(str[i]) << endl;
                ans.push_back(make_pair(str[i], get_hash(str[i])));
                str.erase(it);i--;
                str.erase(str.begin()+i);i--;
            }
        }  
    }
    for(ll i = 0; i < ans.size() ; i++){
        cout <<"Hash of string \"" << ans[i].first << "\" is " << ans[i].second << endl;
    }

    
    return 0;
}
