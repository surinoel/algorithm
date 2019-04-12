#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<int> d(k + 1);
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j - a[i] >= 0) {
				if (j - a[i] == 0 || (d[j - a[i]] != 0 && (d[j] == 0 || d[j] > d[j - a[i]] + 1))) {
					d[j] = d[j - a[i]] + 1;
				}
			}
		}
	}
	if (d[k] == 0) {
		cout << "-1\n";
	}
	else {
		cout << d[k] << '\n';
	}
	return 0;
}
