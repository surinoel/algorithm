#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc; cin >> tc;
	while (tc--) {
		bool ok = true;
		stack<char> st;
		string s;
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') {
				st.push('(');
			}
			else {
				if (st.empty()) {
					ok = false;
					break;
				}
				else {
					st.pop();
				}
			}
		}
		if (ok && st.empty()) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}