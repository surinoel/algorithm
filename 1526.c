#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char buf[64];

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = n; i >= 4; i--) {
		bool ok = true;
		sprintf(buf, "%d", i);
		for (int i = 0; i < strlen(buf); i++) {
			if (!(buf[i] == '4' || buf[i] == '7')) {
				ok = false;
				break;
			}
		}
		if (ok) {
			printf("%d\n", i);
			return 0;
		}
	}

	return 0;
}
