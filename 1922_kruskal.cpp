#include <tuple>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int p[1001];

struct Edge {
	int n1, n2, dist;
	bool operator < (const Edge &other) const {
		return dist < other.dist;
	}
};

int Find(int x) {
	if (p[x] == x) return x;
	else return p[x] = Find(p[x]);
}

void Union(int x, int y) {
	int px = Find(x);
	int py = Find(y);
	p[py] = px;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		p[i] = i;
	}
	vector<Edge> edge(m);
	for (int i = 0; i < m; i++) {
		cin >> edge[i].n1 >> edge[i].n2 >> edge[i].dist;
 	}
	sort(edge.begin(), edge.end());

	int ans = 0;
	for (int i = 0; i < m; i++) {
		int px = Find(edge[i].n1);
		int py = Find(edge[i].n2);
		if (px != py) {
			Union(edge[i].n1, edge[i].n2);
			ans += edge[i].dist;
		}
	}

	cout << ans << '\n';
	return 0;
}
