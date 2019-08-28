#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a.begin(), a.end());
	int avg = sum / n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += abs(avg - a[i]);
	}
	
	int start = 0;
	int end = n - 1;
	int mid = (start + end) / 2;
	int ansidx = mid;
	while (start <= end) {
		int tget = a[mid];
		int tsum = 0;
		for (int i = 0; i < n; i++) {
			tsum += abs(tget - a[i]);
		}

		if (ans >= tsum) {
			end = mid - 1;
			ans = tsum;
			ansidx = mid;
		}
		else {
			start = mid + 1;
		}

		mid = (start + end) / 2;
	}

	cout << a[ansidx] << '\n';
	return 0;
}
