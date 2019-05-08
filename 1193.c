#include <stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);
	if (n == 1) {
		printf("1/1\n");
	}
	else {
		int dir = 1;
		int s = 3;
		int cnt = 1; 
		while (1) {
			if (dir == 1) {
				for (int i = 1; i < s; i++) {
					if (++cnt == n) {
						printf("%d/%d\n", i, s - i);
						goto end;
					}
				}
			}
			else {
				for (int i = 1; i < s; i++) {
					if (++cnt == n) {
						printf("%d/%d\n", s - i, i);
						goto end;
					}
				}
			}

			s += 1;
			dir *= -1;
		}
	}

end: 
	return 0;
}
