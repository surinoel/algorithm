#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

int dist[100001];
int coin[4] = { 1, 2, 5, 7 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	memset(dist, -1, sizeof(dist));
	dist[0] = 0;

	queue<int> q;
	q.push(1); dist[1] = 1;
	q.push(2); dist[2] = 1;
	q.push(5); dist[5] = 1;
	q.push(7); dist[7] = 1;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		
		for (int k = 0; k < 4; k++) {
			if (x + coin[k] <= 100000 && dist[x + coin[k]] == -1) {
				dist[x + coin[k]] = dist[x] + 1;
				q.push(x + coin[k]);
			}
		}
	}

	cout << dist[n] << '\n';
	return 0;
}
