#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define min(n, m) n > m ? m : n

int a[1000002];
int d[1000002];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc;
	cin >> tc;
	int inf = 1e8;
	for (int test_case = 1; test_case <= tc; test_case++) {
		fill(d, d + 1000002, inf);
		memset(a, 0, sizeof(a));
		int n, k; 
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int x; cin >> x;
			a[i] = x;
		}
		cin >> k;

		d[0] = 0;
		for (int i = 1; i <= n; i++) {
			// lgN
			int left, right, mid;
			left = 0, right = i - 1;
			mid = (left + right) / 2;
			int idx = -1;
			while (left <= right) {
				if (a[i] - a[mid] <= k) {
					idx = mid;
					right = mid - 1;
				}
				else {
					left = mid + 1;
				}
				mid = (left + right) / 2;
			}
			if (idx == -1) {
				break;
			}
			d[i] = d[idx] + 1;
		}

		int ans = (d[n] == inf) ? -1 : d[n];
		
		cout << "Case #" << test_case << '\n';
		cout << ans << '\n';
	}
	
	return 0;
}
