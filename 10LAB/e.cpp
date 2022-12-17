#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, q, a, b, c;;
	cin >> n >> q;
	int matrix[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}
	while (q--) {
		cin >> a >> b >> c;
        a--; b--; c--;
		if(matrix[a][b] == 0){
            cout << "NO\n";
            continue;
        }
        if(matrix[a][c] == 0){
            cout << "NO\n";
            continue;
        }
        if(matrix[b][c] == 0){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
	}

	return 0;
}