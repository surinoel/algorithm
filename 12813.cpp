#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<string> st[5];
	string a, b;
	cin >> a >> b;
	for (int i = 0; i < a.size(); i++) {
		int n1 = a[i] - '0';
		int n2 = b[i] - '0';

		st[0].push_back(to_string(n1*n2));
		if (n1 + n2 == 0) st[1].push_back(to_string(0));
		else st[1].push_back(to_string(1));
		
		if (n1 + n2 == 1) st[2].push_back(to_string(1));
		else st[2].push_back(to_string(0));

		if (n1 == 0) st[3].push_back(to_string(1));
		else st[3].push_back(to_string(0));

		if (n2 == 0) st[4].push_back(to_string(1));
		else st[4].push_back(to_string(0));
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < st[i].size(); j++) {
			cout << st[i][j];
		}
		cout << '\n';
	}

	return 0;
}
