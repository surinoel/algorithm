#include <stdio.h>

int a[1000001];

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		a[i] = i + 1;
	}
	int left, right;
	left = 0, right = n;
	while (1) {
		if (!a[++left]) {
			printf("%d\n", a[left - 1]);
			break;
		}
		a[right++] = a[left++];
	}
	
	return 0;
}
