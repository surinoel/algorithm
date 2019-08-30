#include <string>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int select = 0;
	while (n--) {
		string op;
		int val;
		cin >> op;
		if (op == "add") {
			cin >> val;
			select |= (1 << val);
		}
		else if (op == "check") {
			cin >> val;
			if (select & (1 << val)) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (op == "remove") {
			cin >> val;
			select &= ~(1 << val);
		}
		else if (op == "toggle") {
			cin >> val;
			if (select & (1 << val)) {
				select &= ~(1 << val);
			}
			else {
				select |= (1 << val);
			}
		}
		else if (op == "all") {
			select = (1 << 21) - 1;
		}
		else if (op == "empty") {
			select = 0;
		}
	}
	return 0;
}
