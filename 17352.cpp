#include <tuple>
#include <queue>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int dist[300001];
vector<int> mat[300001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n - 2; i++) {
		int x, y;
		cin >> x >> y;
		mat[x].push_back(y);
		mat[y].push_back(x);
	}
	
	queue<int> q;
	memset(dist, -1, sizeof(dist));
	q.push(1);
	dist[1] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < mat[x].size(); i++) {
			if (dist[mat[x][i]] == -1) {
				dist[mat[x][i]] = dist[x] + 1;
				q.push(mat[x][i]);
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		if (dist[i] == -1) {
			cout << 1 << ' ' << i << '\n';
			break;
		}
	}

	return 0;
}
