#include <queue>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

vector<int> place[1001];
int ind[1001];
int buildtime[1001];
long long exittime[1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc;
	cin >> tc;
	while (tc--) {
		memset(ind, 0, sizeof(ind));
		memset(buildtime, 0, sizeof(buildtime));
		memset(exittime, 0, sizeof(exittime));
		for (int i = 0; i < 1001; i++) {
			place[i] = vector<int>();
		}

		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			cin >> buildtime[i];
		}
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			place[x].push_back(y);
			ind[y] += 1;
		}
		int lastplace; cin >> lastplace;

		queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (ind[i] == 0) {
				exittime[i] = buildtime[i];
				q.push(i);
			}
		}

		while (!q.empty()) {
			int x = q.front();
			q.pop();

			for (int k = 0; k < place[x].size(); k++) {
				int node = place[x][k];
				ind[node] -= 1;
				if (ind[node] == 0) {
					q.push(node);
				}
				if (exittime[node] < exittime[x] + buildtime[node]) {
					exittime[node] = exittime[x] + buildtime[node];
				}
			}
		}

		cout << exittime[lastplace] << '\n';
	}

	return 0;
}
