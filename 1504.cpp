#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

#define min(n, m) n > m ? m : n

struct edge {
	int to, cost;
	edge(int to, int cost) : to(to), cost(cost) {
	}
};

vector<edge> a[801];
int dist[3][801];
bool check[801];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		a[x].push_back(edge(y, d));
		a[y].push_back(edge(x, d));
	}
	int inf = 2100000000;
	for (int i = 0; i < 3; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = inf;
		}
	}
	int n1, n2;
	cin >> n1 >> n2;
	vector<int> nd = { 1, n1, n2 };
	for (int i = 0; i < nd.size(); i++) {
		int st = nd[i];
		dist[i][st] = 0;
		memset(check, false, sizeof(check));
		for (int j = 0; j < n - 1; j++) {
			int m, d = inf;
			for (int k = 1; k <= n; k++) {
				if (check[k] == false && d > dist[i][k]) {
					d = dist[i][k];
					m = k;
				}
			}
			check[m] = true;
			for (int j = 0; j < a[m].size(); j++) {
				int y = a[m][j].to;
				if (dist[i][y] > dist[i][m] + a[m][j].cost) {
					dist[i][y] = dist[i][m] + a[m][j].cost;
				}
			}
		}
	}
	
	int ans;
	if ((dist[0][n1] == inf || dist[1][n2] == inf || dist[2][n] == inf) &&
		(dist[0][n2] == inf || dist[2][n1] == inf || dist[1][n] == inf)) {
		ans = -1;
	}
	else {
		ans = min(dist[0][n1] + dist[1][n2] + dist[2][n],
			dist[0][n2] + dist[2][n1] + dist[1][n]);
	}
	
	cout << ans << '\n';
	return 0;
}
