#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

const char buf[20] = "use the stairs";
int dist[1000001];

int dx[2] = { 1, -1 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int F, S, G, U, D;
	cin >> F >> S >> G >> U >> D;

	memset(dist, -1, sizeof(dist));
	queue<int> q;
	q.push(S);
	dist[S] = 0;

	dx[0] = U * dx[0];
	dx[1] = D * dx[1];

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < 2; i++) {
			int tx = x + dx[i];
			if (tx < 1 || tx > F || dist[tx] != -1) continue;
			dist[tx] = dist[x] + 1;
			q.push(tx);
		}
	}

	if (dist[G] == -1) {
		cout << buf << '\n';
	}
	else {
		cout << dist[G] << '\n';
	}

	return 0;
}
