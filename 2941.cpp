#include <string>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s; cin >> s;
	int count = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'c') {
			if (s[i + 1] == '=') {
				count += 1;
				i += 1;
			}
			else if (s[i + 1] == '-') {
				count += 1;
				i += 1;
			}
			else {
				count += 1;
			}
		}
		else if (s[i] == 'd') {
			if (s[i + 1] == 'z') {
				if (s[i + 2] == '=') {
					count += 1;
					i += 2;
				}
				else {
					count += 1;
				}
			}
			else if (s[i + 1] == '-') {
				count += 1;
				i += 1;
			}
			else {
				count += 1;
			}
		}
		else if (s[i] == 'l' && s[i + 1] == 'j') {
			count += 1;
			i += 1;
		}
		else if (s[i] == 'n' && s[i + 1] == 'j') {
			count += 1;
			i += 1;
		}
		else if (s[i] == 's' && s[i + 1] == '=') {
			count += 1;
			i += 1;
		}
		else if (s[i] == 'z' && s[i + 1] == '=') {
			count += 1;
			i += 1;
		}
		else {
			count += 1;
		}
	}

	cout << count << '\n';
	return 0;
}
