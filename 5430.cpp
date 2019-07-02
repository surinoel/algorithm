#include <deque>
#include <cstdio>
#include <cstring>

using namespace std;

char buf[100001];

int main(void) {
	int tc;
	scanf("%d\n", &tc);

	while (tc--) {
		deque<int> dq; int qsize;
		memset(buf, 0, sizeof(buf));
		scanf("%s", buf);
		int n; scanf("%d\n", &n);
		char op; scanf("%c", &op);
		for (int i = 0; i < n; i++) {
			int x; scanf("%d,", &x);
			dq.push_back(x);
		}
		scanf("%c\n", &op);

		int dir = 1;
		int len = strlen(buf);
		for (int i = 0; i < len; i++) {
			if (buf[i] == 'R') {
				dir *= -1;
			}
			else {
				if (dq.empty()) {
					printf("error\n");
					goto end;
				}
				else {
					if (dir == 1) {
						dq.pop_front();
					}
					else {
						dq.pop_back();
					}
				}
			}
		}

		printf("[");
		qsize = dq.size();
		if (dir == 1) {
			for (int i = 0; i < qsize; i++) {
				if (i == qsize - 1) {
					printf("%d", dq[i]);
				}
				else {
					printf("%d,", dq[i]);
				}
			}
		}
		else {
			for (int i = qsize - 1; i >= 0; i--) {
				if (i == 0) {
					printf("%d", dq[i]);
				}
				else {
					printf("%d,", dq[i]);
				}
			}
		}
		printf("]\n");
	end:
		;
	}

	return 0;
}
