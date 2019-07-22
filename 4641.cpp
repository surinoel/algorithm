#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

bool check[101];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (1) {
		memset(check, 0, sizeof(check));
		int x; cin >> x;
		if (x == -1) return 0;
		vector<int> v;
		v.push_back(x);
		check[x] = true;
		while (1) {
			cin >> x;
			if (x == 0) break;
			v.push_back(x);
			check[x] = true;
		}
		sort(v.begin(), v.end());
		int ans = 0;
		for (int i = 0; i < v.size(); i++) {
			if (v[i] + v[i] > v[v.size() - 1]) break;
			if (check[v[i] + v[i]]) ans += 1;
		}
		cout << ans << '\n';
	}
}
