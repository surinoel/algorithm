#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		
		bool ok = true;
		for (int i = 0; i < 1000; i++) {
			vector<int> b(n);
			for (int j = 0; j < n; j++) {
				if (j == n - 1) {
					b[j] = abs(a[j] - a[0]);
				}
				else {
					b[j] = abs(a[j] - a[j + 1]);
				}
			}
			bool iszero = true;
			for (int j = 0; j < n; j++) {
				if (b[j] != 0) {
					iszero = false;
					break;
				}
			}
			if (iszero) {
				ok = false;
				break;
			}
			a = b;
		}
		if (!ok) {
			cout << "ZERO\n";
		}
		else {
			cout << "LOOP\n";
		}
	}

	return 0;
}
