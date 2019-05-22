#include <iostream>

using namespace std;

#define max(n, m) n > m ? n : m
int a[1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int ans = 0;
	int tmp = 0;
	int prev = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] - prev > 0) {
			tmp += a[i] - prev;
			ans = max(ans, tmp);
		}
		else {
			tmp = 0;
		}
		prev = a[i];
	}

	cout << ans << '\n';

	return 0;
}
