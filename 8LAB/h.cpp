#include <bits/stdc++.h>
using namespace std;
#define ll long long

string max_substr(string, string);

int main(){string str;
    int n; cin>>n >>str;
    for(int i=1; i<n; i++){
        string s1; cin>>s1;
        str = max_substr(str, s1);
    }
    cout<<str;
}

string max_substr(string s, string s1){
    ll max_occ=0, left, ht1, ht;
    vector<int> minyo; minyo.assign(100000, 0);
    for(int i=0; i<s1.size(); i++){
        ht =0;
        ht1 = (s1[i]-96)%1000000000; //берется по одному хэшу от первого стринга
        for(int j=s.size()-1; j>=0; j--){
            ht=(s[j]-96) %1000000000; //и сравнивается по убыванию с хэшами чаров второго стринга
            if(ht==ht1) minyo[j+1]=minyo[j]+1; //если совпадение по буквам снт++
            else minyo[j+1]=0;
            if(minyo[j+1]>max_occ){
                max_occ=minyo[j+1];
                left=j-max_occ+1;
            }
        }
    }
    if(max_occ==0)return "";
    return s.substr(left, max_occ);
}