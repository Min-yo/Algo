#include <bits/stdc++.h>
using namespace std;

vector<int> prefixFunction(string str) {
	vector<int> pi(str.length());
	for (int i = 1; i < str.length(); i++) {
		int j = pi[i - 1];
		while (j > 0 && str[i] != str[j]) j = pi[j - 1];
		if (str[i] == str[j]) j++;
		pi[i] = j;
	}
	return pi;
}

int main(){
    string str; cin >> str;
	vector<int> indxs = prefixFunction(str);
	cout << str.size()-indxs.back();
	return 0;
}