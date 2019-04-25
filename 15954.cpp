#include <cmath>
#include <vector>
#include <iomanip>
#include <iostream>

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
	
	long double ans = 2147483647;
	for (int i = 0; i < n; i++) {
		vector<int> q;
		int tmp = 0;
		for (int j = i; j < n; j++) {
			q.push_back(v[j]);
			tmp += v[j];
			if (q.size() < k) {
				continue;
			}

			long double avg = tmp / (long double)q.size();
			long double sum = 0;

			for (int u = i; u < j + 1; u++) {
				sum += (v[u] - avg) * (v[u] - avg);
			}
			sum /= (long double)q.size();
			sum = sqrt(sum);
			if (ans > sum) {
				ans = sum;
			}
		}
	}
	
	cout << fixed << setprecision(10) << ans << '\n';
	return 0;
}
