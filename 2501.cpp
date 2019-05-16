#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	int idx = 0;
	for (int i = 1; i <= n; i++) {
		if (n%i == 0) {
			if (++idx == k) {
				cout << i << '\n';
				return 0;
			}
		}
	}
	cout << 0 << '\n';
	return 0;
}
