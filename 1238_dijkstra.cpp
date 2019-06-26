#include <queue>
#include <vector>
#include <iostream>

using namespace std;

struct edge {
	int to, cost;
	edge(int to, int cost) : to(to), cost(cost) {

	}
};

vector<edge> a[1001];
int dist[1001][1001];
bool visit[1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, z;
	cin >> n >> m >> z;
	for (int i = 0; i < m; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		a[x].push_back(edge(y, d));
	}

	int inf = 100000000;
	for (int i = 1; i <= n; i++) {
		memset(visit, false, sizeof(visit));
		for (int j = 1; j <= n; j++) {
			dist[i][j] = inf;
		}
		priority_queue<pair<int, int>, vector<pair<int, int>>> q;
		dist[i][i] = 0;
		q.push(make_pair(0, i));

		while (!q.empty()) {
			int node, cost;
			node = q.top().second;
			cost = q.top().first;
			q.pop();

			if (visit[node]) continue;
			visit[node] = true;

			for (int k = 0; k < a[node].size(); k++) {
				int y = a[node][k].to;
				if (dist[i][y] > dist[i][node] + a[node][k].cost) {
					dist[i][y] = dist[i][node] + a[node][k].cost;
					q.push(make_pair(-dist[i][y], y));
				}
			}
		}
	}
	
	int ans = -1;
	for (int i = 1; i <= n; i++) {
		if (dist[i][z] + dist[z][i] > ans) {
			ans = dist[i][z] + dist[z][i];
		}
	}
	
  	cout << ans << '\n';
	return 0;
}
