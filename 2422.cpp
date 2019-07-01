#include <iostream>

using namespace std;

int n, m;
int p[201][201];

int dfs(int idx, int cnt, int st) {
	if (cnt == 3) {
		return 1;
	}

	int ret = 0;
	for (int i = idx + 1; i <= n; i++) {
		if (p[idx][i] == 0 && p[st][i] == 0) {
			ret += dfs(i, cnt + 1, st);
		}
	}
	
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		p[x][y] = x;
		p[y][x] = y;
	}
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		ret += dfs(i, 1, i);
	}
	cout << ret << '\n';
	return 0;
}
