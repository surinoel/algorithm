#include <math.h>
#include <stdio.h>

#define MID 4500

int a[9000];

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		a[MID + x] += 1;
	}

	double sum = 0;
	for (int i = 0; i < 9000; i++) {
		if (a[i] > 0) {
			sum += (i - MID) * a[i];
		}
	}
	printf("%.lf\n", round(sum/n));
	
	int cnt = 0, ans;
	for (int i = 0; i < 9000; i++) {
		for (int j = 0; j < a[i]; j++) {
			if (++cnt == n / 2 + 1) {
				ans = i - MID;
			}
		}
	}
	printf("%d\n", ans);
	
	ans = -1;
	int val = 0, flag;
	for (int i = 0; i < 9000; i++) {
		if (ans == -1 || a[i] > ans) {
			flag = 1;
			val = i - MID;
			ans = a[i];
		}
		else if (a[i] == ans && flag) {
			flag = 0;
			val = i - MID;
		}
	}
	printf("%d\n", val);

	int left, right;
	for (int i = 0; i < 9000; i++) {
		if (a[i] > 0) {
			left = i - MID;
			break;
		}
	}

	for (int i = 8999; i >= 0; i--) {
		if (a[i] > 0) {
			right = i - MID;
			break;
		}
	}
	printf("%d\n", right - left);

	return 0;
}
