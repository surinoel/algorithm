#include <iostream>

using namespace std;

int a[1000];
int d1[1000];
int d2[1000];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		d1[i] = 1;
		d2[i] = 1;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i] && d1[i] < d1[j] + 1) {
				d1[i] = d1[j] + 1;
			}
		}
	}

	for (int i = n - 2; i >= 0; i--) {
		for (int j = n - 1; j > i; j--) {
			if (a[j] < a[i] && d2[i] < d2[j] + 1) {
				d2[i] = d2[j] + 1;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (d1[i] + d2[i] > ans) {
			ans = d1[i] + d2[i] - 1;
		}
	}

	cout << ans << '\n';
	return 0;
}