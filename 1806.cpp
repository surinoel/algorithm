#include <iostream>

using namespace std;

int a[100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int left, right, sum, minlen;
	left = right = 0;
	sum = a[left];
	minlen = -1;
	if (m == 0) {
		cout << 0 << '\n';
	}
	else {
		while (left <= right && right < n) {
			if (sum == m) {
				if (minlen == -1 || minlen > right - left + 1) {
					minlen = right - left + 1;
				}
				sum += a[++right];
			}
			else if (sum < m) {
				sum += a[++right];
			}
			else {
				if (minlen == -1 || minlen > right - left + 1) {
					minlen = right - left + 1;
				}
				sum -= a[left++];
				if (left > right && left < n) {
					left = right;
					sum = a[right];
				}
			}
		}
		if (minlen == -1) minlen = 0;
		cout << minlen << '\n';
	}

	return 0;
}
