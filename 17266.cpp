#include <iostream>

using namespace std;

int a[100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("data.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}

	int ans;
	int left = 0, right = n;
	int mid = (left + right) / 2;
	while (left <= right) {
		int d = a[0], idx = 0;
		bool ok = true;
		for (int i = 0; i <= n; i++) {
			if (!(i >= d - mid && i <= d + mid)) {
				if (++idx == m) {
					ok = false;
					goto end;
				}
				d = a[idx];
				if (!(i - 1 >= d - mid && i - 1 <= d + mid)) {
					ok = false;
					goto end;
				}
			}
		}
	end:
		if (ok) {
			ans = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}

		mid = (left + right) / 2;
	}
	
	cout << ans << '\n';
	return 0;
}
