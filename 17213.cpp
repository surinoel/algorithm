#include <iostream>

using namespace std;

int n, m;
int ans;

void go(int kind, int cnt) {
	if (cnt == m - n) {
		ans += 1;
		return;
	}
	if (kind == n || cnt > m - n) {
		return;
	}

	for (int i = 0; i <= m - n; i++) {
		go(kind + 1, cnt + i);
	}

	return;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i <= m - n; i++) {
		go(1, i);
	}

	cout << ans << '\n';
	return 0;
}
