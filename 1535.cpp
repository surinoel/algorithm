#include <cstring>
#include <iostream>

using namespace std;

#define max(a, b) a > b ? a : b

int hp[21], happy[21];
int d[21][101];
int n;

int go(int idx, int h) {
	if (idx == n + 1) {
		return 0;
	}

	if (d[idx][h] > 0) return d[idx][h];

	int ans = go(idx + 1, h);
	if (h - hp[idx] > 0) {
		ans = max(ans, go(idx + 1, h - hp[idx]) + happy[idx]);
	}
	d[idx][h] = ans;
	
	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> hp[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> happy[i];
	}

	memset(d, -1, sizeof(d));
	cout << go(1, 100) << '\n';

	return 0;
}
