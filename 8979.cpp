#include <stdio.h>
#include <string.h>

typedef struct __country {
	int idx, gold, silver, bronze;
	int rank = 0;
} Country;

Country d[1001];

bool cmp(const Country &a, const Country &b) {
	if (a.gold == b.gold) {
		if (a.silver == b.silver) {
			if (a.bronze == b.bronze) {
				return true;
			}
			else {
				return a.bronze > b.bronze;
			}
		}
		else {
			return a.silver > b.silver;
		}
	}
	else {
		return a.gold > b.gold;
	}
}

bool is_same(const Country &a, const Country &b) {
	if (a.gold == b.gold) {
		if (a.silver == b.silver) {
			if (a.bronze == b.bronze) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

int main(void) {
	int n, k;
	scanf("%d %d", &n, &k);
	
	for (int i = 1; i <= n; i++) {
		int x, g, s, b;
		scanf("%d %d %d %d", &x, &g, &s, &b);
		d[i].idx = x;
		d[i].gold = g;
		d[i].silver = s;
		d[i].bronze = b;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= n - i; j++) {
			if (!cmp(d[j], d[j + 1])) {
				Country tmp;
				memcpy(&tmp, &d[j], sizeof(Country));
				memcpy(&d[j], &d[j + 1], sizeof(Country));
				memcpy(&d[j + 1], &tmp, sizeof(Country));
			}
		}
	}

	int rank = 1;
	d[1].rank = 1;
	if (d[1].idx == k) {
		printf("1\n");
	}
	else {
		for (int i = 2; i <= n; i++) {
			if (is_same(d[i - 1], d[i])) {
				d[i].rank = d[i - 1].rank;
			}
			else {
				d[i].rank = i;
			}
			if (d[i].idx == k) {
				printf("%d\n", d[i].rank);
				break;
			}
		}
	}

	return 0;
}
