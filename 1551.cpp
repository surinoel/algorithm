#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	
	istringstream sin(s);
	vector<int> a;
	string num;
	while (getline(sin, num, ',')) {
		a.push_back(stoi(num));
	}

	for (int i = 0; i < m; i++) {
		vector<int> b;
		for (int i = 0; i < a.size() - 1; i++) {
			b.push_back(a[i + 1] - a[i]);
		}
		a = b;
	}

	for (int i = 0; i < a.size(); i++) {
		if (i != a.size() - 1) cout << a[i] << ',';
		else cout << a[i];
	}
	cout << '\n';
	return 0;
}
