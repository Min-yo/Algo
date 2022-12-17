#include <bits/stdc++.h>
using namespace std;


int main() {
    vector<int> p, min_st;
    int ans = 0, n;
	cin >> n;
    vector<vector<int> > g(n);
    vector<bool> visited(n);
	for (int i = 0; i < n; i++) {
		g[i].resize(n);
	}
	p.assign(n, -1);
	min_st.assign(n, 1e9);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> g[i][j];
		}
	}
	min_st[0] = 0;
	for (int i = 0; i < n; i++) {
		int cur_vertex = -1;
		for (int j = 0; j < n; j++) {
			if (!visited[j] && (cur_vertex == -1 || min_st[j] < min_st[cur_vertex])) {
				cur_vertex = j;
			}
		}

		visited[cur_vertex] = true;
		if (p[cur_vertex] != -1) {
			ans += g[cur_vertex][p[cur_vertex]];
		}
		for (int j = 0; j < n; j++) {
			if (g[cur_vertex][j] < min_st[j]) {
				min_st[j] = g[cur_vertex][j];
				p[j] = cur_vertex;
			}
		}
	}
	cout << ans;
	return 0;
}