#include <map>
#include <string>
#include <iostream>

using namespace std;

char mat[100][100];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	map<char, char> mp;
	mp['.'] = '.'; 
	mp['O'] = 'O';
	mp['-'] = '|';
	mp['|'] = '-';
	mp['/'] = '\\';
	mp['\\'] = '/';
	mp['^'] = '<';
	mp['<'] = 'v';
	mp['v'] = '>';
	mp['>'] = '^';

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}

	for (int i = m - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			cout << mp[mat[j][i]];
		}
		cout << '\n';
	}
	cout << '\n';

	return 0;
}
