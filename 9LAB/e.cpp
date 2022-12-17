#include <bits/stdc++.h>
using namespace std;

vector<long long> partssearch(string str) {
	vector<long long> minyo(str.size());
	for (long long eachtry = 1; eachtry < str.size(); eachtry++) {
		long long butnoteach = minyo[eachtry - 1];
		while (butnoteach > 0 && str[eachtry] != str[butnoteach]) butnoteach = minyo[butnoteach - 1];
		if (str[eachtry] == str[butnoteach]) butnoteach++;
		minyo[eachtry] = butnoteach;
	}
	return minyo;
}

int main() {
	long long numver;
	cin >> numver;
	while (numver--) {
		string str;
		long long someothernumber;
		cin >> str >> someothernumber;
		vector<long long> minyo = partssearch(str);
		//long long k_times = str.size() - minyo.back();
		cout << (str.size() - minyo.back())*(someothernumber - 1) + str.size() << endl;
	}
	return 0;
}