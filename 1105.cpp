#include <string>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string a, b;
	cin >> a >> b;
	int ans = 0;
	if (a.length() == b.length()) {
		for (int i = 0; i < a.length(); i++) {
			if (a[i] == b[i]) {
				if (a[i] == '8') {
					ans += 1;
				}
			}
			else {
				break;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
