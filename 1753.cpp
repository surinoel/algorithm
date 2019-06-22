#include <tuple>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

struct edge {
	int to, cost;
	edge(int to, int cost) : to(to), cost(cost) {}
};

vector<edge> a[20001];
int dist[20001];
bool check[20001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, st;
	cin >> n >> m >> st;
	for (int i = 0; i < m; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		a[x].push_back(edge(y, d));
	}
	int inf = 2100000000;
	for (int i = 1; i <= n; i++) {
		dist[i] = inf;
	}

	priority_queue<pair<int, int>> q;
	dist[st] = 0;
	q.push(make_pair(0, st));

	while (!q.empty()) {
		int d, nd;
		tie(d, nd) = q.top();
		q.pop();

		if (check[nd]) continue;
		check[nd] = true;

		for (int i = 0; i < a[nd].size(); i++) {
			int y = a[nd][i].to;
			if (dist[y] > dist[nd] + a[nd][i].cost) {
				dist[y] = dist[nd] + a[nd][i].cost;
				q.push(make_pair(-dist[y], y));
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (dist[i] == inf) {
			cout << "INF\n";
		}
		else {
			cout << dist[i] << '\n';
		}
	}

	return 0;
}
