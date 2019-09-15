#include <map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

map<string, char> m = {
	{ "000000", 'A' },
	{ "001111", 'B' },
	{ "010011", 'C' },
	{ "011100", 'D' },
	{ "100110", 'E' },
	{ "101001", 'F' },
	{ "110101", 'G' },
	{ "111010", 'H' }
};

vector<string> vs = {
	"000000",
	"001111",  
	"010011",  
	"011100",  
	"100110",  
	"101001",  
	"110101",  
	"111010" 
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	string s;
	cin >> n >> s;
	string ans = "";
	for (int i = 0; i < n; i++) {
		string tmp = s.substr(6 * i, 6);
		if (m.count(tmp)) {
			ans += m[tmp];
		}
		else {
			bool ok = false;
			for (int j = 0; j < vs.size(); j++) {
				int cnt = 0;
				for (int k = 0; k < vs[j].size(); k++) {
					if (tmp[k] != vs[j][k]) {
						cnt += 1;
					}
				}
				if (cnt == 1) {
					ok = true;
					ans += (char)('A' + j);
				}
			}
			if (!ok) {
				cout << i + 1 << '\n';
				return 0;
			}
		}
	}
	
	cout << ans << '\n';
	return 0;
}
