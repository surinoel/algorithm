#include <queue>
#include <vector>
#include <iostream>

using namespace std;

#define max(n, m) n > m ? n : m

vector<int> job[10001];
int jobtime[10001];
int exitjob[10001];
int ind[10001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> jobtime[i];
		int m; cin >> m;
		for (int j = 0; j < m; j++) {
			int x; cin >> x;
			job[x].push_back(i);
			ind[i] += 1;
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0) {
			q.push(i);
			exitjob[i] = jobtime[i];
		}
	}

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < job[x].size(); i++) {
			int node = job[x][i];
			ind[node] -= 1;
			if (ind[node] == 0) {
				q.push(node);
			}
			exitjob[node] = max(jobtime[node] + exitjob[x], exitjob[node]);
		}
	}

	int ans = -1;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, exitjob[i]);
	}

	cout << ans << '\n';
	return 0;
}
