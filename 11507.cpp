#include <string>
#include <iostream>

using namespace std;

int card[4][14];
int cnt[4];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
  
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		int cidx;
		if (s[i] == 'P') cidx = 0;
		else if (s[i] == 'K') cidx = 1;
		else if (s[i] == 'H') cidx = 2;
		else if (s[i] == 'T') cidx = 3;

		int num = 0;
		num += 10 * (s[i + 1] - '0') + s[i + 2] - '0';
		card[cidx][num] += 1;

		i += 2;
	}

	bool ok = true;
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= 13; j++) {
			if (card[i][j] > 1) {
				ok = false;
			}
			if (card[i][j] == 0) {
				cnt[i] += 1;
			}
		}
	}

	if (!ok) {
		cout << "GRESKA\n";
	}
	else {
		for (int i = 0; i < 4; i++) {
			cout << cnt[i] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
