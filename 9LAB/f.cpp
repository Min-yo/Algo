#include <bits/stdc++.h>
using namespace std;

vector<int> prefixFunction(string s) {
	vector<int> pi(s.length());
	for (int i = 1; i < s.length(); i++) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j]) j = pi[j - 1];
		if (s[i] == s[j]) j++;
		pi[i] = j;
	}
	return pi;
}

int main(){
    string str, ptr, str_conc_ptr;
    cin >> str >> ptr;
    str_conc_ptr = ptr + '#' + str;
    vector<int> ans, pi = prefixFunction(str_conc_ptr);
	for (int i = ptr.size() + 1; i < str_conc_ptr.size(); i++) {
		if (pi[i] == ptr.size()) {
			ans.push_back(i - 2 * ptr.size());
		}
	}
    cout << ans.size() << endl;
    for(auto i : ans){
        cout << i + 1 << " ";
    }

    return 0;   
}