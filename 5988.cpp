#include <string>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc;
	cin >> tc;
	while (tc--) {
		string s;
		cin >> s;
		if ((s[s.size() - 1] - '0') % 2) {
			cout << "odd\n";
		}
		else {
			cout << "even\n";
		}
	}
	return 0;
}
