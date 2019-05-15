#include <iostream>

using namespace std;

int city[201];

int getparent(int idx) {
	if (city[idx] == idx) return idx;
	return city[idx] = getparent(city[idx]);
}

void unioncity(int a, int b) {
	int ap = getparent(a);
	int bp = getparent(b);
	if (ap < bp) city[bp] = ap;
	else city[ap] = bp;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		city[i] = i;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int ok; cin >> ok;
			if (ok) {
				unioncity(i, j);
			}
		}
	}

	int st; cin >> st;
	for (int i = 1; i < m; i++) {
		int comp; cin >> comp;
		if (getparent(st) != getparent(comp)) {
			cout << "NO\n";
			return 0;
		}
		else {
			st = comp;
		}
	}
	cout << "YES\n";
	return 0;
}
