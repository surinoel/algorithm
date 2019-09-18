#include <string>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	while (cin >> n) {
		if (n == 1) {
			cout << 1 << '\n';
			continue;
		}
		int cnt = 2;
		long long div = 1;
		while (div = ((div * 10) % n + 1) % n) {
			cnt += 1;
		}
		cout << cnt << '\n';
	}

	return 0;
}
