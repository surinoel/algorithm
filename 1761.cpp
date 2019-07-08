#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<pair<int, int>> tree[40001];
int d[40001];
int p[40001];
int dist[40001];

int LCA(int x, int y)
{
	int dist1 = 0, dist2 = 0;
	if (d[x] < d[y]) {
		swap(x, y);
	}
	while (d[x] != d[y]) {
		x = p[x];
	}
	while (x != y) {
		x = p[x];
		y = p[y];
	}

	return x;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		tree[x].push_back(make_pair(y, d));
		tree[y].push_back(make_pair(x, d));
	}
	
	queue<int> q;
	q.push(1);
	p[1] = -1; d[1] = 0; dist[1] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < tree[x].size(); i++) {
			int y = tree[x][i].first;
			if (p[y] != 0) continue;
			d[y] = d[x] + 1;
			p[y] = x;
			dist[y] = dist[x] + tree[x][i].second;
			q.push(y);
		}
	}

	int tc;
	cin >> tc;
	while (tc--) {
		int x, y;
		cin >> x >> y;
		int lca = LCA(x, y);
		cout << dist[x] - dist[lca] + dist[y] - dist[lca] << '\n';
	}

	return 0;
}
