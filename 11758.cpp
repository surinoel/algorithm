/* 삼각형의 면적이 최대 int 범위를 넘지 않으므로 자료형은 int로 해도 무방하다 */
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long x1, x2, x3, y1, y2, y3;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;

	long long s = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
	if (s < 0) {
		cout << -1 << '\n';
	}
	else if (s == 0) {
		cout << 0 << '\n';
	}
	else {
		cout << 1 << '\n';
	}

	return 0;
}
