#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int s, l;
	cin >> s >> l;

	bool ok = false;
	int x;
	int len;
	for (int i = l; i <= 100; i++) {
		x = (s - ((i - 1)*i) / 2) / i;
		if ((s - ((i - 1)*i) / 2) % i != 0 || x < 0) continue;
		len = i;
		ok = true;
		break;
	}

	if (ok) {
		for (int i = 0; i < len; i++) {
			cout << x + i << ' ';
		}
		cout << '\n';
	}
	else {
		cout << "-1\n";
	}
	return 0;
}
