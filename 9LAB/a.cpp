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

bool findSubstrings(string txt, string pat) {
	vector<int> ans;
	string concat = pat + '#' + txt;
	vector<int> pi = prefixFunction(concat);
	for (int i = pat.size() + 1; i < concat.size(); i++) {
		if (pi[i] == pat.size()) {
			return true;
		}
	}
	return false;
	
}

int main() {
	string str, ptr;
	cin >> str >> ptr;
	string minyo = str;
	long long  cnt = 1;
	while (str.size() < ptr.size()) {
		str += minyo;
		cnt++;
	}
	if (findSubstrings(str, ptr)) {
		cout << cnt;
		return 0;
	}
	if (findSubstrings(str + minyo, ptr)) {
		cout << ++cnt;
		return 0;
	}
	cout << -1;
	return 0;
}
