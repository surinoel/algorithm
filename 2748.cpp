#include <iostream>

using namespace std;

long long memo[100];

long long fibo(int n) {
	if (n == 0 || n == 1) {
		return n;
	}
	if (memo[n] > 0) {
		return memo[n];
	}

	memo[n] = fibo(n - 1) + fibo(n - 2);
	return memo[n];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	cout << fibo(n) << '\n';

	return 0;
}
