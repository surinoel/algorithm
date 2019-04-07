#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<int> d(n);
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		d[i] = v[i%n] * v[(i + 1) % n] * v[(i + 2) % n] * v[(i + 3) % n];
		sum += d[i];
	}
	for (int i = 0; i < k; i++) {
		int sidx; cin >> sidx;
		if (--sidx == -1) {
			sidx = n - 1;
		}
		for (int j = 0; j < 4; j++) {
			d[sidx] = -d[sidx];
			sum += 2*d[sidx];
			if (--sidx == -1) {
				sidx = n - 1;
			}
		}
		cout << sum << '\n';
	}
	return 0;
}