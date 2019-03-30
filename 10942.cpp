#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int d[2001][2001];

int go(int s, int e, vector<int> &v) {
	if (s == e) {
		return 1;
	}
	else if (s + 1 == e) {
		int val = (v[s] == v[e]) ? 1 : 0;
		return val;
	}
	
	if (d[s][e] >= 0) {
		return d[s][e];
	}

	if (v[s] == v[e]) {
		d[s][e] = go(s + 1, e - 1, v);
	}
	else {
		d[s][e] = 0;
	}
	return d[s][e];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(d, -1, sizeof(d));
	freopen("data.txt", "r", stdin);
	int n; cin >> n;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	
	int tc; cin >> tc;
	while (tc--) {
		int x, y;
		cin >> x >> y;
		int ans = go(x, y, v);
		cout << ans << '\n';
	}

	return 0;
}