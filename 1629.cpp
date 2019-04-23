#include <iostream>

using namespace std;

long long calc(long long a, long long b, long long c) {
	if (b == 0) {
		return 1;
	}
	else if (b == 1) {
		return a % c;
	}
	else if (b % 2 == 0) {
		long long tmp = calc(a, b / 2, c) % c;
		return ((tmp % c) * (tmp % c)) % c;
	}
	else {
		return ((a % c) * (calc(a, b - 1, c) % c)) % c;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long a, b, c;
	cin >> a >> b >> c;
	cout << calc(a, b, c) % c << '\n';
	return 0;
}
