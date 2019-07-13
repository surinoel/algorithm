#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < 100; i++) {
		n /= 100;
		int a, b;
		a = i / 10;
		b = i % 10;
		n = n * 10 + a;
		n = n * 10 + b;
		if (n%m == 0) {
			cout << a << b << '\n';
			return 0;
		}
	}

	return 0;
}
