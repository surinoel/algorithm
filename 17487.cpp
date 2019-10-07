#include <string>
#include <sstream>
#include <iostream>

using namespace std;

// a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
bool check[] = { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	getline(cin, s);
	int left = 0, right = 0;
	int rest = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			if (check[s[i] - 'a']) right += 1;
			else left += 1;
		}
		else if (s[i] >= 'A' && s[i] <= 'Z') {
			if (check[s[i] - 'A']) right += 1;
			else left += 1;
			rest += 1;
		}
		else if (s[i] == ' ') {
			rest += 1;
		}
	}

	while (rest--) {
		if (left > right) {
			right += 1;
		}
		else {
			left += 1;
		}
	}

	cout << left << ' ' << right << '\n';
	return 0;
}
