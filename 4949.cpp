#include <stack>
#include <sstream>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	for (;;) {
		getline(cin, s);
		if (s == ".") break;
		stack<char> st;
		bool ok = true;
		for (int i = 0; i < s.length() - 1; i++) {
			if (s[i] == '(' || s[i] == '[') {
				st.push(s[i]);
			}
			else if (s[i] == ')') {
				if (st.empty() || st.top() != '(') {
					ok = false;
				}
				else {
					st.pop();
				}
			}
			else if (s[i] == ']') {
				if (st.empty() || st.top() != '[') {
					ok = false;
				}
				else {
					st.pop();
				}
			}
		}
		if (ok && st.empty()) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
	}

	return 0;
}
