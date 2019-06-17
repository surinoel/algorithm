#include <iostream>

using namespace std;

int a[101];
int d[101];
int p[101];
bool b[101];
int ans = 0;

int dfs(int idx, int cnt, int parent) {
	if (d[idx] != 0) {
		if (p[idx] == parent) {
			ans += cnt - d[idx];
			return d[idx];
		}
		else {
			return -1;
		}
	}

	d[idx] = cnt;
	p[idx] = parent;
	int ret = dfs(a[idx], cnt + 1, parent);
	if (ret == -1 || cnt < ret) {
		b[idx] = false;
	}
	else if(cnt >= ret) {
		b[idx] = true;
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		a[i] = x;
	}

	for (int i = 1; i <= n; i++) {
		if (d[i] != 0) continue;
		dfs(i, 1, i);
	}
	
	cout << ans << '\n';
	for (int i = 1; i <= n; i++) {
		if (b[i] == 1) {
			cout << i << '\n';
		}
	}

	return 0;
}
