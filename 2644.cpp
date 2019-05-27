#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

int graph[101][101];
int dist[101];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, a1, a2;
	cin >> n >> a1 >> a2;
	int tc;
	cin >> tc;
	while (tc--) {
		int x, y;
		cin >> x >> y;
		graph[x][y] = 1;
		graph[y][x] = 1;
	}

	memset(dist, -1, sizeof(dist));
	queue<int> q;
	q.push(a1);
	dist[a1] = 0;
	
	while (!q.empty()) {
		int p = q.front();
		q.pop();

		for (int k = 1; k <= n; k++) {
			if (dist[k] == -1 && graph[p][k] == 1) {
				dist[k] = dist[p] + 1;
				q.push(k);
			}
		}
	}

	cout << dist[a2] << '\n';
	return 0;
}
