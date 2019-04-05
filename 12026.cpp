#include <iostream>
#include <string>
#include <vector>
using namespace std;

char get_prev(char x) {
	if (x == 'B') {
		return 'J';
	}
	else if (x == 'O') {
		return 'B';
	}
	else if (x == 'J') {
		return 'O';
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("data.txt", "r", stdin);
	int n; string s;
	cin >> n;
	cin >> s;
	vector<int> d(n, -1);
	d[0] = 0;
	for (int i = 1; i < n; i++) {
		char now = s[i];
		char prev = get_prev(now);
		for (int j = 0; j < i; j++) {
			if (d[j] == -1) continue;
			if (s[j] != prev) continue;
			int cost = d[j] + (i - j)*(i - j);
			if (d[i] == -1 || d[i] > cost) {
				d[i] = cost;
			}
		}
	}
	cout << d[n - 1] << '\n';
	return 0;
}