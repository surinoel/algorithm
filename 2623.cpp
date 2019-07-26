#include <queue>
#include <vector>
#include <iostream>

using namespace std;

vector<int> mat[1001];
int ind[1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int k; cin >> k;
		int x; cin >> x;
		for (int j = 0; j < k - 1; j++) {
			int y; cin >> y;
			ind[y] += 1;
			mat[x].push_back(y);
			x = y;
		}
	}

	vector<int> ans;
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0) {
			q.push(i);
			ans.push_back(i);
		}
	}
	
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < mat[x].size(); i++) {
			int y = mat[x][i];
			if (--ind[y] == 0) {
				q.push(y);
				ans.push_back(y);
			}
		}
	}

	if (ans.size() == n) {
		for (auto x : ans) {
			cout << x << '\n';
		}
	}
	else {
		cout << 0 << '\n';
	}

	return 0;
}
