#include <tuple>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

vector<pair<int, int>> graph[1001];
bool check[1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		graph[x].push_back(make_pair(y, d));
		graph[y].push_back(make_pair(x, d));
	}

	priority_queue<pair<int, int>> q;
	check[1] = true;
	for (int i = 0; i < graph[1].size(); i++) {
		q.push(make_pair(-graph[1][i].second, graph[1][i].first));
	}

	int ans = 0;
	while (!q.empty()) {
		int edge, dist;
		tie(dist, edge) = q.top();
		q.pop();

		if (check[edge]) continue;
		check[edge] = true;
		ans += -dist;
		for (int k = 0; k < graph[edge].size(); k++) {
			q.push(make_pair(-graph[edge][k].second, graph[edge][k].first));
		}
	}

	cout << ans << '\n';
	return 0;
}
