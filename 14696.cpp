#include <cstring>
#include <iostream>

using namespace std;

struct shape {
	int star, round, square, tri;
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int round;
	cin >> round;
	while (round--) {
		struct shape a, b;
		memset(&a, 0, sizeof(struct shape));
		memset(&b, 0, sizeof(struct shape));

		int n, m;
		cin >> n;
		while (n--) {
			int x; cin >> x;
			if (x == 4) a.star += 1;
			else if (x == 3) a.round += 1;
			else if (x == 2) a.square += 1;
			else if (x == 1) a.tri += 1;
		}
		cin >> m;
		while (m--) {
			int x; cin >> x;
			if (x == 4) b.star += 1;
			else if (x == 3) b.round += 1;
			else if (x == 2) b.square += 1;
			else if (x == 1) b.tri += 1;
		}

		char ans;
		if (a.star != b.star) {
			ans = a.star > b.star ? 'A' : 'B';
		}
		else {
			if (a.round != b.round) {
				ans = a.round > b.round ? 'A' : 'B';
			}
			else {
				if (a.square != b.square) {
					ans = a.square > b.square ? 'A' : 'B';
				}
				else {
					if (a.tri != b.tri) {
						ans = a.tri > b.tri ? 'A' : 'B';
					}
					else {
						ans = 'D';
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
