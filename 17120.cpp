#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long n;
	int m;
	cin >> n >> m;
	if (n <= 5) {
		for (int i = 2; i <= n; i++) {
			m = (m + 1) % 2;
			cout << m << '\n';
		}
	}
	else {
		cout << "Love is open door\n";
	}

	return 0;
}
