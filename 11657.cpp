#include <climits>
#include <iostream>

using namespace std;

typedef struct __edge {
	int from, to, cost;
} Edge;

int dist[501];
Edge edge[6000];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		dist[i] = 2100000000;
	}
	for (int i = 0; i < m; i++) {
		cin >> edge[i].from >> edge[i].to >> edge[i].cost;
	}

	dist[1] = 0;
	bool negative_cycle = false;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			int from = edge[j].from;
			int to = edge[j].to;
			int cost = edge[j].cost;

			if (dist[from] != 2100000000 && dist[to] > dist[from] + cost) {
				if (i == n) negative_cycle = true;
				dist[to] = dist[from] + cost;
			}
		}
	}
	if (negative_cycle) {
		cout << -1 << '\n';
	}
	else {
		for (int i = 2; i <= n; i++) {
			if (dist[i] == 2100000000) {
				cout << -1 << '\n';
			}
			else {
				cout << dist[i] << '\n';
			}
		}
	}

	return 0;
}
