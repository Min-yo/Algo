#include<bits/stdc++.h>
using namespace std;

const int d11 = 31;
vector<int> src_occ(string str, string ptr, int q = 1e9 + 7) {
    int p = 0, t = 0, h = 1, i, j;
    vector<int> ans;
    for (i = 0; i < ptr.size() - 1; i++)
        h = (h * d11) % q;

    for (i = 0; i < ptr.size(); i++) {
        p = (d11 * p + ptr[i]) % q;
        t = (d11 * t + str[i]) % q;
    }

    for (i = 0; i <= str.size() - ptr.size(); i++) {
        if (p == t) {
            for (j = 0; j < ptr.size(); j++) {
                if (str[i + j] != ptr[j]) break;
            }
            if (j == ptr.size()) {
                ans.push_back(i);
            }
        }

        if (i < str.size() - ptr.size()) {
            t = (d11 * (t - str[i] * h) + str[i + ptr.size()]) % q;
            if (t < 0) t += q;
        }
    }
    return ans;
}

int main(){
    while(true){
        int n; cin >> n;
        if(n == 0) break;
        vector<string> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        string str; cin >> str;
        int max = 0;
        for(int i = 0; i < n; i++){
            vector<int> inds = src_occ(str, v[i]);
            if(inds.size() > max){
                max = inds.size();
            }
        }
        cout << max << endl;
        for(int i = 0; i < n; i++){
            vector<int> inds = src_occ(str, v[i]);
            if(inds.size() == max){
                cout << v[i] << endl;
            }
            
        }

    }
    

    return 0;
}