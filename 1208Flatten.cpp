#include <cstring>
#include <iostream>

using namespace std;

#define max(n, m) n > m ? n : m
#define min(n, m) n > m ? m : n

int h[100];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int tc = 1; tc <= 10; tc++) {
		memset(h, 0, sizeof(h));
		int n;
		cin >> n;
		int left = 101, right = -1;
		for (int j = 0; j < 100; j++) {
			int x; cin >> x;
			h[x] += 1;
			left = min(left, x);
			right = max(right, x);
		}

		while (left <= right && n > 0) {
			if (h[left] == h[right]) {
				if (n >= h[left]) {
					n -= h[left];
					h[left + 1] += h[left];
					h[right - 1] += h[right];
					h[left] = h[right] = 0;
					left++, right--;
				}
				else {
					h[left] -= n;
					h[right] -= n;
					n = 0;
				}
			}
			else if (h[left] > h[right]) {
				if (n >= h[right]) {
					n -= h[right];
					h[left] -= h[right];
					h[left + 1] += h[right];
					h[right - 1] += h[right];
					h[right] = 0;
					right--;
				}
				else {
					h[left] -= n;
					h[right] -= n;
					n = 0;
				}
			}
			else {
				if (n >= h[left]) {
					n -= h[left];
					h[right] -= h[left];
					h[right - 1] += h[left];
					h[left + 1] += h[left];
					h[left] = 0;
					left++;
				}
				else {
					h[left] -= n;
					h[right] -= n;
					n = 0;
				}
			}
		}

		cout << "#" << tc << " " << right - left << '\n';
 	}
	return 0;
}
