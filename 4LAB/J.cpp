#include <algorithm>
#include <iostream>
#include <vector>

#define ll long long
using namespace std;

void solve(vector<ll>& ans, ll n, ll ar[]){
    ll mid = n/2;
    ans.push_back(ar[mid]);
    if (n > 1){
        solve(ans, n/2, ar);
        solve(ans, n/2, ar + mid + 1);
    }
}


ll ar[(1<<16)];

int main(){
    ll n;
    scanf("%lli", &n);
    n = (1<<n)-1;
    for(ll i = 0; i < n; i++) scanf("%lli", ar + i);
    sort(ar, ar+n);
    vector<ll> ans;
    solve(ans, n, ar);
    for(ll i : ans) printf("%lli ", i);
    return 0;
}
