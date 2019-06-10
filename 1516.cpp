#include <queue>
#include <vector>
#include <iostream>

using namespace std;

#define max(n, m) n > m ? n : m

vector<int> place[501];
int buildtime[501];
int exittime[501];
int ind[501];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> buildtime[i];
		while (1) {
			int x; cin >> x;
			if (x == -1) break;

			place[x].push_back(i);
			ind[i] += 1;
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0) {
			q.push(i);
			exittime[i] = buildtime[i];
		}
	}

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < place[x].size(); i++) {
			int node = place[x][i];
			ind[node] -= 1;
			if (ind[node] == 0) {
				q.push(node);
			}
			exittime[node] = max(exittime[node], exittime[x] + buildtime[node]);
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << exittime[i] << '\n';
	}

	return 0;
}
