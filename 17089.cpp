#include <iostream>
#include <vector>

using namespace std;

vector<int> v[4001];
bool visit[4001];
int ans = -1;

void dfs(int x, int idx, vector<int> &d) {
	if (x == idx && d.size() == 3) {
		int sum = 0;
		for (auto p : d) {
			sum += v[p].size() - 2;
		}
		if (ans == -1 || ans > sum) {
			ans = sum;
		}
		return;
	}

	if (visit[idx] == true || d.size() == 3) {
		return;
	}

	visit[idx] = true;
	d.push_back(idx);

	for (int i = 0; i < v[idx].size(); i++) {
		dfs(x, v[idx][i], d);
	}

	d.pop_back();
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("data.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	for (int i = 1; i <= n; i++) {
		memset(visit, false, sizeof(visit));
		vector<int> d;
		dfs(i, i, d);
	}

	cout << ans << '\n';

	return 0;
}
