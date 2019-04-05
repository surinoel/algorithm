#include <iostream>
#include <vector>

using namespace std;

int n;
int ans = -1;
bool broken[8];

void go(int idx, vector<pair<int,int>> &v) {
	if (idx == n) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (broken[i]) {
				cnt += 1;
			}
		}
		if (ans == -1 || cnt > ans) {
			ans = cnt;
		}
		return;
	}

	if (broken[idx]) {
		go(idx + 1, v);
	}
	else {
		bool ok = false;
		for (int k = 0; k < n; k++) {
			if (idx == k) continue;
			if (broken[k]) continue;

			v[idx].first -= v[k].second;
			v[k].first -= v[idx].second;
			if (v[idx].first <= 0) {
				broken[idx] = true;
			}
			if (v[k].first <= 0) {
				broken[k] = true;
			}
			ok = true;
			go(idx + 1, v);
			v[idx].first += v[k].second;
			v[k].first += v[idx].second;
			if (v[idx].first > 0) {
				broken[idx] = false;
			}
			if (v[k].first > 0) {
				broken[k] = false;
			}

		}
		if (!ok) {
			go(idx + 1, v);
		}
	}
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	go(0, v);
	cout << ans << '\n';

	return 0;
}