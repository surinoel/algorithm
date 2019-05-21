#include <stdio.h>

int a[3000];

int main(void) {
	int n; 
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		a[i] = i + 1;
	}
	int left, right;
	left = 0, right = n;

	while (1) {
		printf("%d ", a[left++]);
		if (!a[left]) break;
		a[right++] = a[left++];
 	}
	printf("\n");

	return 0;
}
