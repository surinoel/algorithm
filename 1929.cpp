#include <iostream>
#include <cstring>

using namespace std;

bool check[1000001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("data.txt", "r", stdin);
	int n, m;
	cin >> n >> m;

	check[1] = true;
	for (int i = 2; i <= m; i++) {
		if (check[i] == false) {
			for (int j = i+i; j <= m; j += i) {
				check[j] = true;
			}
		}
	}

	for (int i = n; i <= m; i++) {
		if (!check[i]) {
			cout << i << '\n';
		}
	}
	return 0;
}