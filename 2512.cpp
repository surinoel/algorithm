#include <iostream>

using namespace std;

#define max(a, b) a > b ? a : b
int d[10000];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int left, right;
	left = 0; right = -1;
	for (int i = 0; i < n; i++) {
		cin >> d[i];
		right = max(right, d[i]);
	}
	long long sum;
	cin >> sum;

	long long ans = 0;
	long long upperlimit = 0;
	int mid = (left + right) / 2;
	while (left <= right) {
		long long tmp = 0;
		for (int k = 0; k < n; k++) {
			if (mid > d[k]) {
				tmp += d[k];
			}
			else {
				tmp += mid;
			}
		}

		if (tmp > sum) {
			right = mid - 1;
		}
		else if (tmp < sum) {
			if (tmp > ans) {
				ans = tmp;
				upperlimit = mid;
			}
			left = mid + 1;
		}
		else {
			upperlimit = mid;
			break;
		}

		mid = (left + right) / 2;
	}

	cout << upperlimit << '\n';
	return 0;
}
