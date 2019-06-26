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

	dist[1] = 0;
	for (int i = 1; i <= n; i++) {
		int d = inf, m;
		for (int j = 1; j <= n; j++) {
			if (check[j] == false && d > dist[j]) {
				m = j;
				d = dist[j];
			}
		}
		check[m] = true;
		for (int i = 0; i < a[m].size(); i++) {
			int y = a[m][i].to;
			if (dist[y] > dist[m] + a[m][i].cost) {
				dist[y] = dist[m] + a[m][i].cost;
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
