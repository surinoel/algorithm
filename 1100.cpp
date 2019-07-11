#include <queue>
#include <string>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int ans = 0;
	for (int i = 0; i < 8; i++) {
		string s;
		cin >> s;
		int h = 1;
		if (i % 2) h = -1;
		for (int j = 0; j < 8; j++) {
			if (h == 1 && s[j] == 'F') ans += 1;
			h *= -1;
		}
	}

	cout << ans << '\n';
	return 0;
}
