#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

int dist[100001];

int dx[6] = { 1, -1, 1, -1, 1, -1 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, n, m;
	cin >> a >> b >> n >> m;
	dx[2] = a * dx[2], dx[3] = a * dx[3];
	dx[4] = b * dx[4], dx[5] = b * dx[5];

	memset(dist, -1, sizeof(dist));
	queue<int> q;
	q.push(n);
	dist[n] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int k = 0; k < 6; k++) {
			int tx = x + dx[k];
			if (tx < 0 || tx > 100000 || dist[tx] != -1) continue;
			dist[tx] = dist[x] + 1;
			q.push(tx);
		}
		int tx = x * a;
		if (!(tx < 0 || tx > 100000 || dist[tx] != -1)) {
			dist[tx] = dist[x] + 1;
			q.push(tx);
		}
		tx = x * b;
		if (!(tx < 0 || tx > 100000 || dist[tx] != -1)) {
			dist[tx] = dist[x] + 1;
			q.push(tx);
		}
	}

	cout << dist[m] << '\n';
	return 0;
}
