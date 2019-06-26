#include <queue>
#include <vector>
#include <iostream>

using namespace std;

struct edge {
	int to, cost;
	edge(int to, int cost) : to(to), cost(cost) {

	}
};

vector<edge> a[101];
int dist[101];
bool check[101];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	int inf = 100000000;
	for (int i = 1; i <= n; i++) {
		dist[i] = inf;
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(edge(y, 1));
		a[y].push_back(edge(x, 1));
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>> q;
	q.push(make_pair(0, 1));
	dist[1] = 0;

	while (!q.empty()) {
		int node, cost;
		node = q.top().second;
		cost = q.top().first;
		q.pop();

		if (check[node]) continue;
		check[node] = true;

		for (int i = 0; i < a[node].size(); i++) {
			int y = a[node][i].to;
			if (dist[y] > dist[node] + a[node][i].cost) {
				dist[y] = dist[node] + a[node][i].cost;
				q.push(make_pair(-dist[y], y));
			}
		}
	}

	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		if (dist[i] != inf) cnt += 1;
	}

	cout << cnt << '\n';
	return 0;
}
