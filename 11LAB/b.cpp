#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, sum = 0;
	cin >> n;
	vector<int> vec(n);
	int min_numb = 1e6;
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
		min_numb = min(min_numb, vec[i]);
		sum += vec[i];
	}
	sum -= min_numb;
	cout << (--n)*min_numb+sum;

	return 0;
}