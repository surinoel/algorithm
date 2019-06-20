#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

vector<pair<int, int>> a[1001];
bool check[1001];
int dist[1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		a[x].push_back(make_pair(y, d));
	}
	int inf = 2100000000;
	for (int i = 1; i <= n; i++) {
		dist[i] = inf;
	}

	int st, ex;
	cin >> st >> ex;
	dist[st] = 0;
	
	for (int i = 0; i < n - 1; i++) {
		int m, d = inf + 1;
		for (int j = 1; j <= n; j++) {
			if (check[j] == false && d > dist[j]) {
				m = j;
				d = dist[j];
			}
		}
		check[m] = true;
		for (int j = 0; j < a[m].size(); j++) {
			int node = a[m][j].first;
			if (dist[node] > dist[m] + a[m][j].second) {
				dist[node] = dist[m] + a[m][j].second;
			}
		}
	}
	
	cout << dist[ex] << '\n';
	return 0;
}
