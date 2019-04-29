#include <math.h>
#include <stdio.h>
#include <string.h>

char buf[4];

int main(void) {
	scanf("%s", buf);
	int d1 = 0;
	for (int i = 0; buf[i] != '\0'; i++) {
		d1 += (buf[i] - '0') * (int)pow(10, i);
	}
	scanf("%s", buf);
	int d2 = 0;
	for (int i = 0; buf[i] != '\0'; i++) {
		d2 += (buf[i] - '0') * (int)pow(10, i);
	}
	printf("%d\n", d1 > d2 ? d1 : d2);
	return 0;
}
