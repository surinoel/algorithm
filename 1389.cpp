#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

int graph[101][101];
int dist[101][101];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
  
	int n, m;
	cin >> n >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		graph[x][y] = 1;
		graph[y][x] = 1;
	}
	
	memset(dist, -1, sizeof(dist));
	for (int i = 1; i <= n; i++) {
		queue<int> q;
		q.push(i);
		dist[i][i] = 0;

		while (!q.empty()) {
			int p = q.front();
			q.pop();

			for (int k = 1; k <= n; k++) {
				if (dist[i][k] == -1 && graph[p][k] == 1) {
					dist[i][k] = dist[i][p] + 1;
					q.push(k);
				}
			}
		}
	}

	int ans;
	int msum = -1;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			sum += dist[i][j];
		}
		if (msum == -1 || msum > sum) {
			msum = sum;
			ans = i;
		}
	}
	
	cout << ans << '\n';
	return 0;
}
