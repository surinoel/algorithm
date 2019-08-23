#include <map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int changeidx[1000];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		string s;
		map<string, int> minfo;
		for (int i = 0; i < n; i++) {
			cin >> s;
			minfo[s] = i;
		}
		for (int i = 0; i < n; i++) {
			cin >> s;
			changeidx[i] = minfo[s];
		}
		vector<string> vs(n);
		for (int i = 0; i < n; i++) {
			cin >> s;
			vs[changeidx[i]] = s;
		}
		for (int i = 0; i < n; i++) {
			cout << vs[i] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
