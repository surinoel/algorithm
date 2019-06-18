#include <climits>
#include <iostream>

using namespace std;

typedef struct __edge {
	int from, to, cost;
} Edge;

int dist[501];
Edge edge[5700];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int inf = INT_MAX;
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m, k;
		cin >> n >> m >> k;
		for (int i = 1; i <= n; i++) {
			dist[i] = inf;
		}
		for (int i = 0; i < m; i++) {
			int from, to, cost;
			cin >> from >> to >> cost;
			edge[2 * i].from = from;
			edge[2 * i].to = to;
			edge[2 * i].cost = cost;
			edge[2 * i + 1].from = to;
			edge[2 * i + 1].to = from;
			edge[2 * i + 1].cost = cost;
		}
		for (int i = 0; i < k; i++) {
			cin >> edge[2 * m + i].from >> edge[2 * m + i].to;;
			int cost; cin >> cost;
			edge[2 * m + i].cost = -cost;
 		}
		
		bool ok = false;
		dist[1] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 2 * m + k; j++) {
				int from = edge[j].from;
				int to = edge[j].to;
				int cost = edge[j].cost;

				if (dist[from] != inf && dist[to] > dist[from] + cost) {
					dist[to] = dist[from] + cost;
					if (i == n) ok = true;
				}
			}
		}
			
		if (ok) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}
