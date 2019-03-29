#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, v;
	cin >> a >> b >> v;
	int d = a - b;
	int u = v - a;
	if (u <= 0) {
		cout << "1\n";
	}
	else {
		if (u%d == 0) {
			cout << u / d + 1 << '\n';
		}
		else {
			cout << u / d + 2 << '\n';
		}
	}
	return 0;
}
