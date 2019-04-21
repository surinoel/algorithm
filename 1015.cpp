#include <vector>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<pair<int, int>> v(n, { -1, -1 });
	for (int i = 0; i < n; i++) {
		cin >> v[i].first;
	}

	for (int i = 0; i < n; i++) {
		int tmp = -1;
		int idx;
		for (int j = 0; j < n; j++) {
			if (v[j].second != -1) continue;
			if (tmp == -1 || tmp > v[j].first) {
				idx = j;
				tmp = v[j].first;
			}
		}
		v[idx].second = i;
	}

	for (int i = 0; i < n; i++) {
		cout << v[i].second << ' ';
	}
	cout << '\n';

	return 0;
}
