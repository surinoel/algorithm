#include <iostream>

using namespace std;

int a[1000];
int d[1000];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		d[i] = 1;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i] && d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
			}
		}
	}

	int ans = -1;
	for (int i = 0; i < n; i++) {
		if (d[i] > ans) {
			ans = d[i];
		}
	}
	cout << ans << '\n';
	return 0;
}