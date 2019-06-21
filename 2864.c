#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char buf1[64], buf2[64];

int main(void) {
	scanf("%s %s", buf1, buf2);

	for (int i = 0; buf1[i] != '\0'; i++) {
		if (buf1[i] == '6') {
			buf1[i] = '5';
		}
	}
	for (int i = 0; buf2[i] != '\0'; i++) {
		if (buf2[i] == '6') {
			buf2[i] = '5';
		}
	}

	int s1, s2;
	s1 = atoi(buf1), s2 = atoi(buf2);
	printf("%d ", s1 + s2);

	for (int i = 0; buf1[i] != '\0'; i++) {
		if (buf1[i] == '5') {
			buf1[i] = '6';
		}
	}
	for (int i = 0; buf2[i] != '\0'; i++) {
		if (buf2[i] == '5') {
			buf2[i] = '6';
		}
	}

	s1 = atoi(buf1), s2 = atoi(buf2);
	printf("%d\n", s1 + s2);

	return 0;
}
