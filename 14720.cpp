#include <iostream>
#include <vector>

using namespace std;

int get_prev(int k) {
	if (k == 0) {
		return 2;
	}
	else if (k == 1) {
		return 0;
	}
	else if (k == 2) {
		return 1;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("data.txt", "r", stdin);
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> d(n, -1);
	int start;
	bool ok = false;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == 0 && !ok) {
			start = i;
			ok = true;
		}
	}
	d[start] = 1;
	for (int i = start + 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (d[j] == -1) continue;
			if (a[j] != get_prev(a[i])) continue;
			int cnt = d[j] + 1;
			if (d[i] == -1 || cnt > d[i]) {
				d[i] = cnt;
			}
		}
	}

	int ans = -1;
	for (int i = 0; i < n; i++) {
		if (ans == -1 || d[i] > ans) {
			ans = d[i];
		}
	}
	cout << ans << '\n';
}