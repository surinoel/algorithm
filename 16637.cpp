#include <vector>
#include <string>
#include <climits>
#include <cstring>
#include <iostream>

using namespace std;

int n;
char s[30];
int total;
int ans = INT_MIN;
bool check[30];
bool visit[30];

int stringtoint(string num) {
	int ans = 0;
	if (num[0] == '-') {
		for (int i = 1; i < num.size(); i++) {
			ans = ans * 10 + (num[i] - '0');
		}
	}
	else {
		for (int i = 0; i < num.size(); i++) {
			ans = ans * 10 + (num[i] - '0');
		}
	}
	
	if (num[0] == '-') ans = -ans;
	return ans;
}

void go(int cnt) {
	if (cnt == total) {
		vector<string> newstr;
		for (int i = 0; i < n; i++) {
			if (!visit[i]) {
				string t = "";
				t += s[i];
				newstr.push_back(t);
			}
			else {
				int a = s[i] - '0', b = s[i + 2] - '0';
				char op = s[i + 1];
				int ans;
				if (op == '+') {
					ans = a + b;
					newstr.push_back(to_string(ans));
				}
				else if (op == '-') {
					ans = a - b;
					newstr.push_back(to_string(ans));
				}
				else if (op == '*') {
					ans = a * b;
					newstr.push_back(to_string(ans));
				}
				i += 2;
			}
		}
		
		int tmp = stringtoint(newstr[0]);
		int ssize = newstr.size();
		for (int i = 0; i < ssize / 2; i++) {
			string op = newstr[2 * i + 1];
			if (op == "+") {
				tmp = tmp + stringtoint(newstr[2 * i + 2]);
			}
			else if (op == "-") {
				tmp = tmp - stringtoint(newstr[2 * i + 2]);
			}
			else if (op == "*") {
				tmp = tmp * stringtoint(newstr[2 * i + 2]);
			}
		}
		if (tmp > ans) {
			ans = tmp;
		}
		return;
	}

	go(cnt + 1);
	if (cnt == 0 || (cnt - 1 >= 0 && check[cnt - 1] == false)) {
		check[cnt] = true;
		visit[2 * cnt] = true;
		visit[2 * cnt + 1] = true;
		visit[2 * cnt + 2] = true;
		go(cnt + 1);
		check[cnt] = false;
		visit[2 * cnt] = false;
		visit[2 * cnt + 1] = false;
		visit[2 * cnt + 2] = false;
	}

	return;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> s;
	total = n / 2;

	go(0);
	cout << ans << '\n';
	return 0;
}
