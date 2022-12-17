#include<bits/stdc++.h>
using namespace std;

const int d = 31;
vector<int> src_occur(string str, string ptr, int q = 1e9 + 7) {
    int p = 0, t = 0, h = 1, i, j;
    vector<int> res;
    for (i = 0; i < ptr.size() - 1; i++)
        h = (h * d) % q;

    for (i = 0; i < ptr.size(); i++) {
        p = (d * p + ptr[i]) % q;
        t = (d * t + str[i]) % q;
    }

    for (i = 0; i <= str.size() - ptr.size(); i++) {
        if (p == t) {
            for (j = 0; j < ptr.size(); j++) {
                if (str[i + j] != ptr[j]) break;
            }
            if (j == ptr.size()) {
                res.push_back(i);
            }
        }

        if (i < str.size() - ptr.size()) {
            t = (d * (t - str[i] * h) + str[i + ptr.size()]) % q;
            if (t < 0) t += q;
        }
    }
    return res;
}

int main(){
    string str; cin >> str;
    int n; cin  >>  n;
    
    while(n--){
        int l, r;
        cin >> l >> r;
        //string sub = s.substr(l-1, r - l + 1);
        string sub = "";
        for(int i = l - 1; i < r; i++){
            sub += str[i];
        }
        vector<int> indices = src_occur(str, sub);
        cout << (indices.size() ==0 ? 1 : indices.size()) << endl;
    }
    return 0;
}