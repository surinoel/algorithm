#include <queue>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

vector<int> graph[1001];
bool check[1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
		
	int tc; cin >> tc;
	while (tc--) {
		for (int i = 0; i <= 1000; i++) {
			graph[i] = vector<int>();
		}
		memset(check, false, sizeof(check));

		int n, m;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}

		queue<int> q;
		q.push(1);
		check[1] = true;

		int ans = 0;
		while (!q.empty()) {
			int x = q.front();
			q.pop();

			for (int k = 0; k < graph[x].size(); k++) {
				int node = graph[x][k];
				if (check[node]) continue;
				check[node] = true;
				q.push(node);
				ans += 1;
			}
		}

		cout << ans << '\n';
	}
	
	return 0;
}
