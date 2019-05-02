#include <cmath>
#include <iostream>

using namespace std;

bool check[10001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 1; i*i <= 10000; i++) {
		check[i*i] = true;
	}
	int a, b;
	cin >> a >> b;
	int ans = -1;
	int sum = 0;
	for (int i = a; i <= b; i++) {
		if (check[i]) {
			if (ans == -1) ans = i;
			sum += i;
		}
	}
	if (ans != -1) {
		cout << sum << '\n';
	}
	cout << ans << '\n';

	return 0;
}
