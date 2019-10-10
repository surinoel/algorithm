#include <queue>
#include <tuple>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int exittime[1001];
int ind[1001];
int ans[1001];
vector<int> graph[1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc;
	cin >> tc;

	while (tc--) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			exittime[i] = 0;
			ind[i] = 0;
			ans[i] = 0;
			graph[i].clear();

			cin >> exittime[i];
		}
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			ind[y] += 1;
			graph[x].push_back(y);
		}

		queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (ind[i] == 0) {
				q.push(i);
				ans[i] = exittime[i];
			}
		}

		while (!q.empty()) {
			int node = q.front();
			q.pop();

			for (int i = 0; i < graph[node].size(); i++) {
				int y = graph[node][i];
				if (--ind[y] == 0) {
					q.push(y);
				}

				if (ans[y] == 0 || ans[y] < ans[node] + exittime[y]) {
					ans[y] = ans[node] + exittime[y];
				}
			}
		}

		int buildnum;
		cin >> buildnum;
		cout << ans[buildnum] << '\n';
	}

	return 0;
}
