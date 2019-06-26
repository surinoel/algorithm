#include <map>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

map<string, int> m;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc;
	cin >> tc;
	cin.ignore();
	while (tc--) {
		string s, ans;
		getline(cin, ans);
		while (getline(cin, s)) {
			if (s == "what does the fox say?") break;
			stringstream ss;
			ss.str(s);
			string v;
			for (int i = 0; ; i++) {
				if (!(ss >> v)) break;
				if (i >= 2) {
					m[v] = 1;
				}
			}
		}
		stringstream ss;
		string v;
		ss.str(ans);
		for (int i = 0; ; i++) {
			if (!(ss >> v)) break;
			if (!m.count(v)) {
				cout << v << ' ';
			}
		}
		cout << '\n';
	}
	
	return 0;
}
