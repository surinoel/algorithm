#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, c, s;
	cin >> a >> b >> c >> s;

	bool ok = false;
	for (int i1 = 0; i1 <= s; i1 += a) {
		for (int i2 = 0; i1 + i2 <= s; i2 += b) {
			for (int i3 = 0; i1 + i2 + i3 <= s; i3 += c) {
				if (s == i1 + i2 + i3) {
					ok = true;
					break;
				}
			}
		}
	}
	
	if (ok) cout << "1\n";
	else cout << "0\n";

	return 0;
}
