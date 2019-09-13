#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int b[1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int maxh = -1, idx;
	for (int i = 0; i < n; i++) {
		int l, h;
		cin >> l >> h;
		b[l] = h;
		if (maxh == -1 || h > maxh) {
			maxh = h;
			idx = l;
		}
	}

	int sum = maxh;
	int pidx = idx;
	for (;;) {
		int ppidx = -1;
		int tmaxh = 0;
		for (int i = pidx - 1; i >= 0; i--) {
			if (b[i] > tmaxh) {
				tmaxh = b[i];
				ppidx = i;
			}
		}
		if (ppidx == -1) {
			break;
		}
		else {
			sum += abs(pidx - ppidx) * tmaxh;
			pidx = ppidx;
		}
	}
	
	pidx = idx;
	for (;;) {
		int ppidx = -1;
		int tmaxh = 0;
		for (int i = pidx + 1; i <= 1000; i++) {
			if (b[i] > tmaxh) {
				tmaxh = b[i];
				ppidx = i;
			}
		}
		if (ppidx == -1) {
			break;
		}
		else {
			sum += abs(pidx - ppidx) * tmaxh;
			pidx = ppidx;
		}
	}

	cout << sum << '\n';
	return 0;
}
