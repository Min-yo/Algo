#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > g;
vector<bool> visited;
vector<int> vec, colors;

bool has_cylce(int v) {
	colors[v] = 1;
	for (int i = 0; i < g[v].size(); i++) {
		int u = g[v][i];
		if (colors[u] == 1) {
			return true;
		}
		if (colors[u] == 0) {
			if (has_cylce(u)) return true;
		}
	}
	colors[v] = 2;
	return false;
}

void tpsrt(int v) {
	visited[v] = true;
	for (int i = 0; i < g[v].size(); i++) {
		int u = g[v][i];
		if (!visited[u]) {
			tpsrt(u);
		}
	}
	vec.push_back(v);
}

int main() {
	int m, n;
	cin >> m >> n;
	colors.resize(m);
	g.resize(m);
	visited.resize(m);
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
	}
	bool cyclic = false;
	for (int i = 0; i < m; i++) {
		if (has_cylce(i)) {
			cyclic = true;
			break;
		}
	}
	if (!cyclic) {
		cout << "Possible\n";
		for (int i = 0; i < m; i++) {
			if (!visited[i]) {
				tpsrt(i);
			}
		}
		for (int i = vec.size() - 1; i >= 0; i--) {
			cout << vec[i] + 1 << " ";
		}
	} else {
		cout << "Impossible";
	}

	return 0;
}