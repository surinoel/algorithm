#include <cmath>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

int ans;
int s;
string ts;
bool ok[10];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> s;
	ts = to_string(s);
	int n;
	cin >> n;
	memset(ok, true, sizeof(ok));
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		ok[x] = false;
	}
	ans = abs(100 - s);

	for (int i = 0; i <= 1000000; i++) {
		string tmp = to_string(i);
		bool isok = true;
		for (int j = 0; j < tmp.size(); j++) {
			int num = tmp[j] - '0';
			if (!ok[num]) {
				isok = false;
				break;
			}
		}
		if (isok) {
			int cnt = tmp.size() + abs(s - i);
			if (ans > cnt) {
				ans = cnt;
			}
		}
	}

	cout << ans << '\n';
	return 0;
}
