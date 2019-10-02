#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc;
	cin >> tc;
	while (tc--) {
		 int n, m, k;
		 cin >> n >> m >> k;
		
		int a = k / n;
		if (k % n == 0) {
			cout << (n * 100) + (k / n) << '\n';
		}
		else {
			a += 1;
			int b = k % n;
			cout << (b * 100) + a << '\n';
		}
	}

	return 0;
}
