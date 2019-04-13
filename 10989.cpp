  #include <iostream>

using namespace std;

int d[10001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	while (n--) {
		int x; cin >> x;
		d[x] += 1;
	}
	for (int i = 1; i <= 10000; i++) {
		for (int j = 0; j < d[i]; j++) {
			cout << i << '\n';
		}
	}
	return 0;
}
