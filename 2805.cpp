#include <iostream>
#include <algorithm>

using namespace std;

long long tree[1000000];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long n, h;
	cin >> n >> h;
	long long left, right, mid;
	left = mid = 0;
	right = -1;
	for (int i = 0; i < n; i++) {
		cin >> tree[i];
		right = max(right, tree[i]);
		mid += tree[i];
	}
	mid /= n;
	long long  ans = -1;
	while (left <= right) {
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			if (tree[i] - mid > 0) {
				sum += tree[i] - mid;
			}
		}
		if (sum < h) {
			right = mid - 1;
		}
		else {
			if (ans == -1 || mid > ans) {
				ans = mid;
			}
			left = mid + 1;
		}
		
		mid = (left + right) / 2;
	}

	cout << ans << '\n';
	return 0;
}
