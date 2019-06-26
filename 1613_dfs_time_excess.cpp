#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

vector<int> a[401];
bool visit[401];

void go(int idx, int y, bool &ok) {
	if (idx == y) {
		ok = true;
		return;
	}
	if (visit[idx]) {
		return;
	}
	visit[idx] = true;
	for (int i = 0; i < a[idx].size(); i++) {
		go(a[idx][i], y, ok);
	}
	return;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
	}
	int m;
	cin >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		bool ok = false;
		memset(visit, false, sizeof(visit));
		go(x, y, ok);
		if (ok) {
			cout << -1 << '\n';
			continue;
		}

		ok = false;
		memset(visit, false, sizeof(visit));
		go(y, x, ok);
		if (ok) {
			cout << 1 << '\n';
			continue;
		}

		cout << 0 << '\n';
	}
	
	return 0;
}
