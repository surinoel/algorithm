#include <iostream>

using namespace std;

int fact(int n) {
	int ans = 1;
	for (int i = 2; i <= n; i++) {
		ans *= i;
	}
	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	int a = fact(n);
	int b = fact(n - k);
	int c = fact(k);

	cout << a / (b*c) << '\n';
	return 0;
}
