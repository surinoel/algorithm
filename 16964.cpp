#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v[100001];
bool visit[100001];
int order[100001];

void dfs(vector<int> &d, int x) {
	visit[x] = true;
	d.push_back(x);
	
	for (int i = 0; i < v[x].size(); i++) {
		if (visit[v[x][i]] == true) continue;
		dfs(d, v[x][i]);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		ans.push_back(x);
		order[x] = i;
	}
	for (int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end(), [](const int &u, const int &v) {
			return order[u] < order[v];
		});
	}
	vector<int> d;
	dfs(d, 1);

	if (d == ans) {
		cout << "1\n";
	}
	else {
		cout << "0\n";
	}

	return 0;
}