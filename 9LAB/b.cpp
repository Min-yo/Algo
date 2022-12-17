#include<bits/stdc++.h> 
using namespace std; 
 
 vector<int> prefixFunction(string s) {
	vector<int> pi(s.size());
	for (int i = 1; i < s.size(); i++) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j]) j = pi[j - 1];
		if (s[i] == s[j]) j++;
		pi[i] = j;
	}
	return pi;
}

vector<int> findSubstrings(string txt, string pat) {
	vector<int> ans;
	string str_conc_ptr = pat + '#' + txt;
	vector<int> pi = prefixFunction(str_conc_ptr);
	for (int i = pat.size() + 1; i < str_conc_ptr.size(); i++) {
		if (pi[i] == pat.size()) {
			ans.push_back(i - 2 * pat.size());
		}
	}
	return ans;
}
 
int main(){ 
    string str, password; 
    long long cnt; 
    cin >> str >> cnt >> password; 
    vector<int> ans = findSubstrings(password, str); 
    if(ans.size() >= cnt){ 
        cout << "YES" << endl; 
    } 
    else{ 
        cout << "NO" << endl; 
    } 
    return 0; 
}