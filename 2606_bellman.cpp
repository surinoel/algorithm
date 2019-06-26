#include <vector>
#include <iostream>

using namespace std;

struct edge {
	int from, to, cost;
	edge(int from, int to, int cost) :
		from(from), to(to), cost(cost) {

	}
};

vector<edge> edg;
int dist[101];

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
		int x, y, d = 1;
		cin >> x >> y;
		edg.push_back(edge(x, y, d));
		edg.push_back(edge(y, x, d));
	}
	
	dist[1] = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < edg.size(); j++) {
			int from, to, cost;
			from = edg[j].from;
			to = edg[j].to;
			cost = edg[j].cost;
			if (dist[from] != inf && dist[to] > dist[from] + cost) {
				dist[to] = dist[from] + cost;
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
