#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<string> v(n);
	string ans = "";
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int j = 0; j < v[0].size(); j++) {
		char tmp = v[0][j];
		bool ok = true;
		for (int i = 1; i < n; i++) {
			if (tmp != v[i][j]) {
				ok = false;
				break;
			}
		}
		if (!ok) {
			ans += '?';
		}
		else {
			ans += tmp;
		}
	}

	cout << ans << '\n';
	return 0;
}
