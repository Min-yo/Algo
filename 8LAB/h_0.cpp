#include <bits/stdc++.h>
#define ll long long
using namespace std;

string find(vector<string> s){
    string m="";
    int mxn=0, l;
    ll ht1=0;
    int a[100000]={0};
    for(int i=0; i<s[1].size(); i++){
        ll ht =0;
        ht1 = (s[1][i]-'a'+1)%1000000000; 
        pair<ll, string> hash;
        for(int j=s[0].size()-1; j>=0; j--){
            ht=(s[0][j] - 'a' + 1)%1000000000;
            if(ht==ht1) a[j+1]=a[j]+1; 
            else a[j+1]=0;
            if(a[j+1]>mxn){
                mxn=a[j+1];
                l=j-mxn+1;
            }
        }
    }
    if(mxn==0)return "";
    return s[0].substr(l, mxn);
}

int main(){
    int n; cin>>n;
    string str, s1; cin>>str;
    for(int i=0; i<n-1; i++){
        cin>>s1;
        vector<string> s;
        s.push_back(str); s.push_back(s1);
        str = find(s);
    }
    cout<<str;
}