#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int e, s, m;
	cin >> e >> s >> m;
	int se, ss, sm;
	se = ss = sm = 1;
	for (int i = 1;; i++) {
		if (se == e && ss == s && sm == m) {
			cout << i << '\n';
			break;
		}
		if (++se == 16) {
			se = 1;
		}
		if (++ss == 29) {
			ss = 1;
		}
		if (++sm == 20) {
			sm = 1;
		}
	}

	return 0;
}
