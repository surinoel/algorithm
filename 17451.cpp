#include <cmath>
#include <iostream>

using namespace std;

double v[300000];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	double ans = v[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		ans = ceil(ans / v[i]) * v[i];
	}

	cout << (long long)ans << '\n';
	return 0;
}
