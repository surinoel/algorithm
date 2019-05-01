#include <string>
#include <iostream>

using namespace std;

bool is_ok[4];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int len; cin >> len;
	string s; cin >> s;

	for (int i = 0; i < len; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			is_ok[0] = true;
		}
		else if (s[i] >= 'a' && s[i] <= 'z') {
			is_ok[1] = true;
		}
		else if (s[i] >= 'A' && s[i] <= 'Z') {
			is_ok[2] = true;
		}
		else {
			is_ok[3] = true;
		}
	}

	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		if (!is_ok[i]) cnt += 1;
	}
	
	if (cnt == 0) {
		if (len - 6 >= 0) cout << 0 << '\n';
		else cout << 6 - len << '\n';
	}
	else {
		if (len + cnt >= 6) cout << cnt << '\n';
		else cout << 6 - len << '\n';
	}

	return 0;
}
