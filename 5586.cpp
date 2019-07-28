#include <stdio.h>
#include <string.h>

char buf[10001];

int main(void) {
	scanf("%s", buf);
	int cnt1 = 0;
	char *ptr = strstr(buf, "JOI");
	while (ptr != NULL) {
		cnt1 += 1;
		ptr = strstr(ptr + 2, "JOI");
	}
	printf("%d\n", cnt1);

	int cnt2 = 0;
	ptr = strstr(buf, "IOI");
	while (ptr != NULL) {
		cnt2 += 1;
		ptr = strstr(ptr + 1, "IOI");
	}
	printf("%d\n", cnt2);

	return 0;
}
