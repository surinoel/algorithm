#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	string s;
	cin >> n;
	getline(cin, s);

	while (n--) {	
		getline(cin, s);

		istringstream f(s);
		string ts;
		vector<string> tokens;
		while (getline(f, ts, ' ')) {
			tokens.push_back(ts);
		}

		for (int i = 0; i < tokens.size(); i++) {
			reverse(tokens[i].begin(), tokens[i].end());
			cout << tokens[i];

			if (i != tokens.size() - 1) cout << " ";
		}
		cout << '\n';
	}

	return 0;
}
