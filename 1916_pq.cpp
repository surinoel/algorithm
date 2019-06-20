#include <queue>
#include <iostream>

using namespace std;

struct edge {
	int to, cost;
	edge(int to, int cost) : to(to), cost(cost) {}
};

vector<edge> a[1001];
int dist[1001];
bool check[1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		a[x].push_back(edge(y, d));
	}
	int inf = 2100000000;
	for (int i = 1; i <= n; i++) {
		dist[i] = inf;
	}
	
	int st, ex;
	cin >> st >> ex;
	priority_queue<pair<int, int>> q;
	q.push(make_pair(0, st));
	dist[st] = 0;
	while (!q.empty()) {
		int node;
		node = q.top().second;
		q.pop();
		
		if (check[node]) continue;
		check[node] = true;
		for (int k = 0; k < a[node].size(); k++) {
			int y = a[node][k].to;
			if (dist[y] > dist[node] + a[node][k].cost) {
				dist[y] = dist[node] + a[node][k].cost;
				q.push(make_pair(-dist[y], y));
			}
		}
	}

	cout << dist[ex] << '\n';
	return 0;
}
