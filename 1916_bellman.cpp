#include <vector>
#include <iostream>

using namespace std;

struct edge {
	int from, to, cost;
	edge() : from(0), to(0), cost(0) {}
	edge(int from, int to, int cost) : from(from), to(to), cost(cost) {}
};

vector<edge> a;
int dist[1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	
	a.resize(m);
	for (int i = 0; i < m; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		a[i] = edge(x, y, d);
	}
	int inf = 2100000000;
	for (int i = 1; i <= n; i++) {
		dist[i] = inf;
	}

	int st, ex;
	cin >> st >> ex;
	dist[st] = 0;

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			int from = a[j].from;
			int to = a[j].to;
			int cost = a[j].cost;
			if (dist[from] != inf && dist[to] > dist[from] + cost) {
				dist[to] = dist[from] + cost;
			}
		}
	}

	cout << dist[ex] << '\n';
	return 0;
}
