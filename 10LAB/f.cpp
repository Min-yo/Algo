#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > g;
vector<bool> visited;
bool flag;
int m, n, a, b;

void dfs(int v) {
	if (v == b) {
		flag = true;
		return;
	}
	visited[v] = true;
	for (auto to : g[v]) {
		if (!visited[to]) {
			dfs(to);
		}
	}
}

int main() {
	cin >> m >> n;
	g.resize(m);
	visited.resize(m);
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cin >> a >> b;
	b--;
	dfs(a--);
	cout << (flag ? "YES" : "NO");


	return 0;
}