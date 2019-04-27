#include <cstdio>

char buf[256];

int main(void) {
	fgets(buf, sizeof(buf), stdin);
	for (int i = 0; buf[i] != '\0'; i++) {
		if (buf[i] >= 'A' && buf[i] <= 'Z') {
			buf[i] = 'A' + ((buf[i] - 'A' + 13) % 26);
		}
		else if (buf[i] >= 'a' && buf[i] <= 'z') {
			buf[i] = 'a' + ((buf[i] - 'a' + 13) % 26);
		}
	}
	printf("%s\n", buf);
	return 0;
}
