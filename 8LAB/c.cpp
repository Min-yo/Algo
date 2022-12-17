#include <bits/stdc++.h>
using namespace std;
#define ll long long
    bool Truth[200005];
    ll power_1[200005];
    ll power_2[200005];
    ll hash_1[200005];
    ll hash_2[200005];
int main() {
    int n;
    string s;
    cin >> s; 
    
    power_1[0] = 1; //first index
    power_2[0] = 1; //second index

    for (int i = 1; i < s.size(); i++) {int j = i-1;
        power_1[i] = (power_1[j]*31)%1000000000;
        power_2[i] = (power_2[j]*37)%1000000007;
    }
    for (int i = 0; i < s.size(); ++i) {int j = i+1;
        hash_1[j] = (hash_1[i] + (s[i]-'a'+ 1)*power_1[i])%1000000000;
        hash_2[j] = (hash_2[i] + (s[i]-'a'+ 1)*power_2[i])%1000000007;
    }
    cin >> n; 
    int left = s.size() + 1, right = 0;

    while(n--){
        string tape; 
        cin >> tape;
        ll hash_t = 0;
        ll hash_t2 = 0;

        for (int i = 0; i < tape.size(); i ++) {
            hash_t = (hash_t + (tape[i] - 'a' + 1) * power_1[i]) % 1000000000;
            hash_t2 = (hash_t2 + (tape[i] - 'a' + 1) * power_2[i]) % 1000000007;
        }
        for (int i = 0; i + tape.size() - 1 < s.size(); i++) {
            ll cur = (hash_1[i + tape.size()] + 1000000000 - hash_1[i]) % 1000000000;
            ll cur1 = (hash_2[i + tape.size()] + 1000000007 - hash_2[i]) % 1000000007;
            if (hash_t * power_1[i]%1000000000 == cur && hash_t2 * power_2[i] % 1000000007 == cur1) {
                bool flag = true;
                int k = 0, j = i;
                while(k < tape.size()){
                    if (tape[k] != s[j]){
                        flag = false;
                        break;
                    }
                    k++;j++;
                }
                if(flag) {
                    left = i, right = i + tape.size() - 1;
                    for (int j = left; j <= right; j++) {
                        Truth[j] = true;
                    }
                }
            }
        }
    }
    for (int i = 0; i < s.size(); i ++) {
        if (!Truth[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}