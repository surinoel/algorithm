#include <iostream>

using namespace std;

int dfs(int k) {
	if (k == 0 || k == 1) {
		return k;
	}

	int i = 1, sum = 0;
	for (i = 1; ; i++) {
		sum += i;
		if (k / sum == 0) {
			sum -= i;
			i--;
			break;
		}
	}
	return i + dfs(k - sum);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	cout << dfs(n) << '\n';
	
	return 0;
}
