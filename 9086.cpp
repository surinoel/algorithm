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
		cout << s.front() << s.back() << '\n';
	}

	return 0;
}
