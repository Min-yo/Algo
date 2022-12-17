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

void findSubstrings(string txt, string pat, vector<string> &ans) {
	string str_conc_ptr = pat + '#' + txt;
	vector<int> pi = prefixFunction(str_conc_ptr);
	for (int i = pat.size() + 1; i < str_conc_ptr.size(); i++) {
		if (pi[i] == pat.size()) {
			if(i-2*pat.size()== 0){
				ans.push_back(txt);
			}
			return;
		}
	}
	return;
}

int main() {
	string city;
	int n;
	cin >> city >> n;
	city[0] += 32;
	vector<string> suggest_cities(n), vec_prefs, finallyguessedtheanswer;
	for (int i = 0; i < n; i++) {
		cin >> suggest_cities[i];
		suggest_cities[i][0] += 32;
	}
	for (int i = 0; i < city.size(); i++) {
		vec_prefs.push_back(city.substr(i, city.size()-i));
		
		
	}
	for(int i = 0; i < city.size(); i++){
		for(int j = 0; j < n; j++){
			findSubstrings(suggest_cities[j], vec_prefs[i], finallyguessedtheanswer);
		}
		if(!finallyguessedtheanswer.empty()){
			cout << finallyguessedtheanswer.size() << endl;
			for(auto i : finallyguessedtheanswer) {
				i[0] -= 32;
				cout << i << endl;
			}
			return 0;
		}
	}
	cout << 0;
	return 0;
}