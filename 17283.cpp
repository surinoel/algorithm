#include <iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	int ans = 0;
	int len = n;
	for (int i = 2; ; i *= 2) {
		if (len * m / 100 <= 5) {
			break;
		}
		len = (len * m) / 100;
		ans += i * len;
	}

	cout << ans << '\n';
	return 0;
}
