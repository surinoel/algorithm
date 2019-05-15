#include <iostream>

using namespace std;

int parent[1000001];

int getparent(int idx) {
	if (parent[idx] == idx) return idx;
	return parent[idx] = getparent(parent[idx]);
}

void union_group(int a, int b) {
	int ap = getparent(a);
	int bp = getparent(b);
	parent[bp] = ap;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, tc;
	cin >> n >> tc;
	
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}

	while (tc--) {
		int op, a, b;
		cin >> op >> a >> b;
		if (!op) {
			union_group(a, b);
		}
		else {
			if (getparent(a) == getparent(b)) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}
	return 0;
}
