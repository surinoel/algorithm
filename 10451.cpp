#include <iostream>
#include <cstring>

using namespace std;

int n;
int a[1001];
bool visit[1001];

void dfs(int x) {
	if (visit[x] == true) {
		return;
	}

	visit[x] = true;
	dfs(a[x]);
	return;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc;
	cin >> tc;

	while (tc--) {
		memset(a, 0, sizeof(a));
		memset(visit, false, sizeof(visit));
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (visit[i] == true) continue;
			ans += 1;
			dfs(i);
		}

		cout << ans << '\n';
	}
}