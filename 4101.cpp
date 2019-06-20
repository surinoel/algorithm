#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (1) {
		int x, y;
		cin >> x >> y;
		if (x == 0 && y == 0) break;
		if (x > y) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}

	return 0;
}
