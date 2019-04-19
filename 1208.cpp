#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, s;
	cin >> n >> s;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	m = n / 2;
	n = n - m;
	vector<int> group1((1 << n));
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			if (i&(1 << j)) {
				group1[i] += v[j];
			}
		}
	}
	vector<int> group2((1 << m));
	for (int i = 0; i < (1 << m); i++) {
		for (int j = 0; j < m; j++) {
			if (i&(1 << j)) {
				group2[i] += v[n + j];
			}
		}
	}
	sort(group1.begin(), group1.end());
	sort(group2.begin(), group2.end(), greater<int>());
	
	int l1, l2;
	l1 = l2 = 0;
	n = (1 << n);
	m = (1 << m);
	long long ans = 0;
	while (l1 < n && l2 < m) {
		int ss = group1[l1] + group2[l2];
		if (ss == s) {
			long long c1 = 1;
			long long c2 = 1;
			l1 += 1;
			l2 += 1;
			while (l1 < n && group1[l1 - 1] == group1[l1]) {
				c1 += 1;
				l1 += 1;
			}
			while (l2 < m && group2[l2 - 1] == group2[l2]) {
				c2 += 1;
				l2 += 1;
			}
			ans += c1 * c2;
		}
		else if (ss > s) {
			l2 += 1;
		}
		else {
			l1 += 1;
		}
	}
	
	if (s == 0) ans -= 1;
	cout << ans << '\n';

	return 0;
}
