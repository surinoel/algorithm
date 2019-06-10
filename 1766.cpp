#include <queue>
#include <vector>
#include <iostream>
#include <functional>

using namespace std;

vector<int> graph[32001];
bool visit[32001];
int ind[32001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		ind[y] += 1;
	}

	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0) {
			q.push(i);
			visit[i] = true;
		}
	}

	while (!q.empty()) {
		int x = q.top();
		q.pop();

		cout << x << ' ';
		for (int i = 0; i < graph[x].size(); i++) {
			int node = graph[x][i];
			ind[node] -= 1;
			if (ind[node] == 0 && !visit[node]) {
				visit[node] = true;
				q.push(node);
			}
		}
	}
  
	cout << '\n';
	return 0;
}
