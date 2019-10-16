#include <stack>
#include <string>
#include <iostream>

using namespace std;

int getPriority(char c) {
	if (c == '(') return 0;
	else if (c == '+' || c == '-') return 1;
	else if (c == '*' || c == '/') return 2;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;
	stack<char> st;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '+' || s[i] == '-' || s[i] == '*'
			|| s[i] == '/' || s[i] == '(' || s[i] == ')') {
			if (s[i] == '(') {
				st.push('(');
			}
			else if (s[i] == ')') {
				while (!st.empty() && st.top() != '(') {
					cout << st.top();
					st.pop();
				}
				st.pop();
			}
			else {
				while (!st.empty() && getPriority(s[i]) <= getPriority(st.top())) {
					cout << st.top();
					st.pop();
				}
				st.push(s[i]);
 			}
		}
		else {
			cout << s[i];
		}
	}
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}

	cout << '\n';
	return 0;
}
