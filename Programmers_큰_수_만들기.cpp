#include <stack>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
	string answer = "";

	int len = number.length();
	stack<char> st;
	for (int i = 0; i < len; i++) {
		char num = number[i];

		while (!st.empty() && k > 0) {
			char tp = st.top();
			if (tp < num) {
				st.pop();
				k--;
			}
			else {
				break;
			}
		}

		st.push(num);
	}

	while (k > 0) {
		st.pop();
		k--;
	}

	while (!st.empty()) {
		answer = st.top() + answer;
		st.pop();
	}

	return answer;
}
