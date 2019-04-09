#include <iostream>
#include <algorithm>

using namespace std;

int a[10001];
int d[10001][3];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		if (i - 1 >= 0) {
			d[i][0] = max(d[i - 1][2], max(d[i - 1][1], d[i - 1][0]));
			d[i][1] = d[i - 1][0] + a[i];
		}
		if (i - 2 >= 0) {
			d[i][2] = d[i - 2][0] + a[i - 1] + a[i];
		}
	}

	cout << max(d[n][0], max(d[n][1], d[n][2])) << '\n';
	return 0;
}