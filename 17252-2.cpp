#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	if (n == 0 || n == 2) {
		cout << "NO\n";
		return 0;
	}
	while (n / 3) {
		if (n % 3 == 2) {
			cout << "NO\n";
			return 0;
		}
		n /= 3;
	}
	if (n % 3 == 2) {
		cout << "NO\n";
	}
	else {
		cout << "YES\n";
	}
	return 0;
}
