#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

vector<pair<int, double>> ad;
bool check[101];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			int idx; double score;
			cin >> idx >> score;
			ad.push_back(make_pair(idx, score));
		}
	}

	sort(ad.begin(), ad.end(), [](const auto &u, const auto &v) {
		return u.second > v.second;
	});

	int cnt = 0;
	double ans = 0;
	for (int i = 0; i < ad.size(); i++) {
		if (!check[ad[i].first]) {
			check[ad[i].first] = true;
			ans += ad[i].second;
			if (++cnt == k) {
				cout << fixed << setprecision(1) << ans << '\n';
				return 0;
			}
		}
	}

	return 0;
}
