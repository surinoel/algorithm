#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int maxv = -1;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (maxv == -1 || x > maxv) {
			maxv = x;
		}
	}
	cout << maxv << '\n';
	return 0;
}
