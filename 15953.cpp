#include <iostream>

using namespace std;

int a_m[6] = { 5000000, 3000000, 2000000, 500000, 300000, 100000 };
int b_m[5] = { 5120000, 2560000, 1280000, 640000, 320000 };
int a[101];
int b[101];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int idx = 1;
	for (int i = 1; i <= 6; i++) {
		for (int j = idx; j < idx + i; j++) {
			a[j] = a_m[i - 1];
		}
		idx += i;
	}

	idx = 1;
	for (int i = 1; i <= 5; i++) {
		int tmp = idx << 1;
		for (int j = idx; j < idx ; j++) {
			b[j] = b_m[i - 1];
		}
		idx <<= 1;
	}

	int tc;
	cin >> tc;
	while (tc--) {
		int x, y;
		cin >> x >> y;
		cout << a[x] + b[y] << '\n';
	}
	return 0;
}
