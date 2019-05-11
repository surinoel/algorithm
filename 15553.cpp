#include <tuple>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<bool> cut(n);
	vector<pair<int, int>> v(n);
	vector<tuple<int, int, int>> comp;
	for (int i = 0; i < n; i++) {
		int t; cin >> t;
		v[i] = make_pair(t, t + 1);
		if (i > 0) {
			comp.push_back(make_tuple(i - 1, i, v[i].first - v[i - 1].second));
		}
	}
	sort(comp.begin(), comp.end(), [](auto &u, auto &v) {
		return get<2>(u) > get<2>(v);
	});

	for (int i = 0; i < k - 1; i++) {
		cut[get<1>(comp[i])] = true;
	}
	
	long long ans = 0;
	long long d1 = 0;
	for (int i = 1; i < n; i++) {
		if (cut[i]) {
			ans += v[i - 1].second - v[d1].first;
			d1 = i;
		}
	}
	ans += v[n - 1].second - v[d1].first;
	cout << ans << '\n';

	return 0;
}
