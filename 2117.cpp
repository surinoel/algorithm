#include <cmath>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int price[42];
int cnt[42];
int mat[20][20];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 1; i <= 41; i++) {
		price[i] = i*i + (i - 1)*(i - 1);
	}
	int tc;
	cin >> tc;
	for (int test_case = 1; test_case <= tc; test_case++) {
		int n, m;
		cin >> n >> m;
		vector<pair<int, int>> homelist;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> mat[i][j];
				if (mat[i][j] == 1) {
					homelist.push_back(make_pair(i, j));
				}
			}
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				memset(cnt, 0, sizeof(cnt));
				int maxdist = -1;
				for (int k = 0; k < homelist.size(); k++) {
					int x = homelist[k].first;
					int y = homelist[k].second;
					
					int distance = abs(i - x) + abs(j - y) + 1;
					cnt[distance] += 1;
					maxdist = max(maxdist, distance);
				}

				for (int k = 1; k <= maxdist; k++) {
					cnt[k] += cnt[k - 1];
				}

				int tmpmax = -1;
				for (int k = 1; k <= maxdist; k++) {
					int tmpprice = m * cnt[k] - price[k];
					if (tmpprice >= 0) {
						tmpmax = max(tmpmax, cnt[k]);
					}
				}

				ans = max(ans, tmpmax);
			}
		}

		cout << "#" << test_case << " " << ans << '\n';
	}
	
	return 0;
}
