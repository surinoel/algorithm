#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> m = { {"R", 0}, {"L", 1}, {"B", 2}, {"T", 3},
{ "RT", 4 },{ "LT", 5 },{ "RB", 6 },{ "LB", 7 } };

int dx[8] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
string mov[50];

pair<int, int> chg(string s) {
	int x, y;
	char c1 = s[0];
	char c2 = s[1];
	y = c1 - 'A';
	x = 8 - (c2 - '0');

	return make_pair(x, y);
}

string rchg(pair<int, int> p) {
	string ans;
	ans = p.second + 'A';
	ans += ('0' + 8 - p.first);
	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s1, s2;
	cin >> s1 >> s2;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> mov[i];
	}
	pair<int, int> k, d;
	k = chg(s1);
	d = chg(s2);

	for (int i = 0; i < n; i++) {
		int idx = m[mov[i]];
		if (k.first + dx[idx] < 0 || k.second + dy[idx] < 0 || k.first + dx[idx] > 7 || k.second + dy[idx] > 7) {
			continue;
		}
		else if (k.first + dx[idx] == d.first && k.second + dy[idx] == d.second) {
			if (!(d.first + dx[idx] < 0 || d.second + dy[idx] < 0 || d.first + dx[idx] > 7 || d.second + dy[idx] > 7)) {
				k = make_pair(k.first + dx[idx], k.second + dy[idx]);
				d = make_pair(d.first + dx[idx], d.second + dy[idx]);
			}
		}
		else {
			k = make_pair(k.first + dx[idx], k.second + dy[idx]);
		}
	}

	cout << rchg(k) << '\n';
	cout << rchg(d) << '\n';

	return 0;
}