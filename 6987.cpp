#include <iostream>

using namespace std;

typedef struct __team {
	int win, draw, lose;
} team;

team t[6];

int go(int a, int b) {
	if (a == 5) {
		int twin, tlose, tdraw;
		twin = tlose = tdraw = 0;
		for (int i = 0; i < 6; i++) {
			twin += t[i].win;
			tlose += t[i].lose;
			tdraw += t[i].draw;
		}
		if (twin + tlose + tdraw == 0) return 1;
		else return -1;
	}

	int ret = -1;
	if (t[a].win > 0 && t[b].lose > 0) {
		t[a].win -= 1;
		t[b].lose -= 1;

		if (b == 5) ret = go(a + 1, a + 2);
		else ret = go(a, b + 1);

		t[a].win += 1;
		t[b].lose += 1;
	}
	if (ret != 1) {
		if (t[b].win > 0 && t[a].lose > 0) {
			t[b].win -= 1;
			t[a].lose -= 1;

			if (b == 5) ret = go(a + 1, a + 2);
			else ret = go(a, b + 1);

			t[b].win += 1;
			t[a].lose += 1;
		}
	}
	if (ret != 1) {
		if (t[b].draw > 0 && t[a].draw > 0) {
			t[b].draw -= 1;
			t[a].draw -= 1;

			if (b == 5) ret = go(a + 1, a + 2);
			else ret = go(a, b + 1);

			t[b].draw += 1;
			t[a].draw += 1;
		}
	}

	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> t[j].win >> t[j].draw >> t[j].lose;
		}
		int ret = go(0, 1);
		if (ret < 0) {
			cout << 0 << ' ';
		}
		else {
			cout << 1 << ' ';
		}
	}
	cout << '\n';
	return 0;
}
