#include <stack>
#include <string>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	stack<char> st;
	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		if (st.empty()) {
			st.push(s[i]);
		}
		else {
			if (s[i] - st.top() == 1) {
				st.push(s[i]);
			}
			else {
				if (st.size() == 3) ans += 1;
				while (!st.empty()) {
					st.pop();
				}
				st.push(s[i]);
			}
		}
	}
	if (st.size() == 3) ans += 1;

	cout << ans << '\n';
	return 0;
}
