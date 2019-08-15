#include <iostream>

using namespace std;

int go(int a, int b) {
	if (b == 0) {
		return 1;
	}
	else if (b == 1) {
		return a % 10;
	}
	
	int ret = go(a, b / 2) % 10;
	ret = ((ret % 10) * (ret % 10)) % 10;
	if (b % 2 == 0) {
		return ret;
	}
	else {
		return ((a % 10) * (ret % 10)) % 10;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
  
	int tc;
	cin >> tc;
	while (tc--) {
		int a, b;
		cin >> a >> b;
		int ret = go(a, b) % 10;
		if (ret == 0) cout << 10 << '\n';
		else cout << ret << '\n';
	}

	return 0;
}
