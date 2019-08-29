#include <stack>
#include <string>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;
	stack<int> st;
	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			st.push(i);
		}
		else {
			if (st.top() + 1 == i) {
				st.pop();
				ans += st.size();
			}
			else {
				st.pop();
				ans += 1;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
