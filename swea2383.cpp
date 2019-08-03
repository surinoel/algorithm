#include <queue>
#include <tuple>
#include <cmath>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc;
	cin >> tc;
	for (int k = 1; k <= tc; k++) {
		int n;
		cin >> n;
		vector<pair<int, int>> ps;
		vector<tuple<int, int, int>> stair;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int x; 
				cin >> x;
				if (x == 1) {
					ps.push_back(make_pair(i, j));
				}
				else if (x > 1) {
					stair.push_back(make_tuple(i, j, x));
				}
			}
		}
		
		int psize = ps.size();
		vector<vector<int>> dist(psize, vector<int>(2));
		for (int i = 0; i < psize; i++) {
			int px = ps[i].first;
			int py = ps[i].second;

			for (int j = 0; j < 2; j++) {
				int sx = get<0>(stair[j]);
				int sy = get<1>(stair[j]);

				dist[i][j] = abs(px - sx) + abs(py - sy);
			}
		}

		int ans = -1;
		for (int i = 0; i < (1 << psize); i++) {
			vector<int> p1, p2;
			for (int j = 0; j < psize; j++) {
				if (i & (1 << j)) {
					p1.push_back(dist[j][0]);
				}
				else {
					p2.push_back(dist[j][1]);
				}
			}
			int stlevel0 = get<2>(stair[0]);
			int stlevel1 = get<2>(stair[1]);

			sort(p1.begin(), p1.end());
			sort(p2.begin(), p2.end());
			int maxt1, maxt2;
			maxt1 = maxt2 = -1;

			if (!p1.empty()) {
				int idx = 0;
				queue<int> q1;
				for (int t = 0; ; t++) {
					bool ok = true;
					while (!q1.empty() && t - q1.front() == stlevel0) {
						q1.pop();
						if (q1.empty() && idx == p1.size()) {
							ok = false;
						}
					}
					if (!ok) {
						maxt1 = t;
						break;
					}
					while (q1.size() < 3 && idx < p1.size() && p1[idx] + 1 <= t) {
						q1.push(t);
						idx++;
					}
				}
			}
			if (!p2.empty()) {
				int idx = 0;
				queue<int> q2;
				for (int t = 0; ; t++) {
					bool ok = true;
					while (!q2.empty() && t - q2.front() == stlevel1) {
						q2.pop();
						if (q2.empty() && idx == p2.size()) {
							ok = false;
						}
					}
					if (!ok) {
						maxt2 = t;
						break;
					}
					while (q2.size() < 3 && idx < p2.size() && p2[idx] + 1 <= t) {
						q2.push(t);
						idx++;
					}
				}
			}

			int tans = max(maxt1, maxt2);
			if (ans == -1 || ans > tans) {
				ans = tans;
			}
		}

		cout << "#" << k << " " << ans << '\n';
	}

	return 0;
}
