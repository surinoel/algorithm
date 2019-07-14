#include <iostream>

using namespace std;

int a[50];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (sum + a[i] > m) {
			cout << i - 1 << '\n';
			return 0;
		}
		sum += a[i];
	}
	cout << n << '\n';
	return 0;
}
