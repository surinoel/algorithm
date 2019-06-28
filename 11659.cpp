#include <iostream>

using namespace std;

int a[100001];
int d[100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		d[i] = d[i - 1] + a[i];
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		cout << d[y] - d[x - 1] << '\n';
	}

	return 0;
}
