#include <cstdio>

int a[100001];
int d[100001];
int p[100001];

int dfs(int idx, int cnt, int parent) {
	if (d[idx] != 0) {
		if (p[idx] == parent) {
			return cnt - d[idx];
		}
		else {
			return 0;
		}
	}

	d[idx] = cnt;
	p[idx] = parent;
	return dfs(a[idx], cnt + 1, parent);
}

int main(void) {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n; 
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			d[i] = p[i] = 0;
		}

		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (d[i] != 0) continue;
			ans += dfs(i, 1, i);
		}
		printf("%d\n", n - ans);
	}
	return 0;
}
