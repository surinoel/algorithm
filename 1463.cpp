#include <cstring>
#include <iostream>

using namespace std;

int d[1000001];

int go(int n) {
	if (n == 1) {
		return 0;
	}
	if (d[n] != -1) {
		return d[n];
	}

	int ans = 1e7;
	if (n % 3 == 0) {
		int tmp = go(n / 3) + 1;
		if (ans > tmp) {
			ans = tmp;
		}
	}
	if (n % 2 == 0) {
		int tmp = go(n / 2) + 1;
		if (ans > tmp) {
			ans = tmp;
		}
	}
	if (n - 1 >= 1) {
		int tmp = go(n - 1) + 1;
		if (ans > tmp) {
			ans = tmp;
		}
	}

	d[n] = ans;
	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	memset(d, -1, sizeof(d));
	cout << go(n) << '\n';

	return 0;
}
