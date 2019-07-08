#include <cstring>
#include <iostream>

using namespace std;

int checks[51];
int checke[51];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc;
	cin >> tc;
	while (tc--) {
		memset(checks, 0, sizeof(checks));
		memset(checke, 0, sizeof(checke));
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x, y, r;
			cin >> x >> y >> r;

			int d = (x - sx) * (x - sx) + (y - sy) * (y - sy);
			if (d < r * r) {
				checks[i] = 1;
			}

			d = (x - ex) * (x - ex) + (y - ey) * (y - ey);
			if (d < r * r) {
				checke[i] = 1;
			}
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans += abs(checks[i] - checke[i]);
		}
		cout << ans << '\n';
	}

	return 0;
}
