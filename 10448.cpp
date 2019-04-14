#include <iostream>

using namespace std;

int d[1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 1; i <= 1000; i++) {
		d[i] = i*(i + 1) / 2;
	}

	int tc; cin >> tc;
	while (tc--) {
		int x; cin >> x;
		bool ok = false;
		for (int i1 = 1; i1 <= 1000; i1++) {
			if (d[i1] >= x) break;
			for (int i2 = 1; i2 <= 1000; i2++) {
				if (d[i1] + d[i2] >= x) break;
				for (int i3 = 1; i3 <= 1000; i3++) {
					if (d[i1] + d[i2] + d[i3] > x) break;
					if (d[i1] + d[i2] + d[i3] == x) {
						ok = true;
						break;
					}
				}
			}
		}
		if (ok) 
			cout << "1\n";
		else 
			cout << "0\n";
	}
	return 0;
}
