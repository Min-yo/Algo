#include<bits/stdc++.h>
using namespace std;
void merge(int left[], int right[], int n, int m) { 
	int result[n+m];
	int l = 0, r = 0, k = 0;
	while (l < n && r < m) {
		if (left[l] <= right[r]) {
			result[k] = left[l];
			l++;
		} else {
			result[k]= right[r];
			r++;
		}k++;
	}
	while (l < n) {
		result[k] = left[l];
		l++;k++;
	}
	while (r < m) {
		result[k] = right[r];
		r++;k++;
	}
	for (int i = 0; i < n+m; i++)
		cout << result[i] << " ";
}

int main() {
    int n, m;
    cin >> n;
    int ar1[n];
    for (int i = 0; i < n; i++)
        cin >> ar1[i];
    cin >> m;
	int ar2[m];
    for (int i = 0; i < m; i++)
        cin >> ar2[i];
	merge(ar1, ar2, n, m);
	return 0;
}
/*
5
4 5 6 7 10
5
2 4 6 7 8
merge into one & sort it
*/