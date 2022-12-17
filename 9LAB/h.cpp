#include <bits/stdc++.h>
using namespace std;

vector<int> prefixFunction(string str) {
	vector<int> pi(str.length()); pi[0] = 0;
	for (int i = 1; i < str.length(); i++) {
		int j = pi[i - 1];
		while (j > 0 && str[i] != str[j]) j = pi[j - 1];
		if (str[i] == str[j]) pi[i] = j+1;
		else pi[i] = 0;
	}
	return pi;
}

int main() {
	string s;
	cin >> s;
	int cnt = 0, sz, j;
	vector<int> pi = prefixFunction(s);
	for (int i = 1; i < s.size(); i++) {
		j = i-1;
		sz = i- pi[j];
		if(pi[j] == 0) continue;
		if((i/sz)%2 == 0 && i%sz == 0) cnt++;
	}
	cout << cnt;

	return 0;
}