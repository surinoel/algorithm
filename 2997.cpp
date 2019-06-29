#include <iostream>
#include <algorithm>

using namespace std;

#define min(n, m) n > m ? m : n

int a[3];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 3; i++) {
		cin >> a[i];
	}
	sort(a, a + 3);
	int diff = (int)1e3;
	for (int i = 1; i < 3; i++) {
		diff = min(a[i] - a[i - 1], diff);
	}
	for (int i = 0; i < 4; i++) {
		int val = a[0] + diff * i;
		bool ok = false;
		for (int j = 0; j < 3; j++) {
			if (val == a[j]) {
				ok = true;
			}
		}
		if (!ok) {
			cout << val << '\n';
			break;
		}
	}
	return 0;
}
