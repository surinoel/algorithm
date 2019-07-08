#include <cstdio>

int a[500001];
int b[500001];
long long ans = 0;

void merge(int start, int end) {
	int mid = (start + end) / 2;
	int i = start;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= end) {
		if (a[i] <= a[j]) {
			b[k++] = a[i++];
		}
		else {
			ans += (j - k - start);
			b[k++] = a[j++];
		}
	}
	while (i <= mid) {
		b[k++] = a[i++];
	}
	while (j <= end) {
		b[k++] = a[j++];
	}

	for (int i = start; i <= end; i++) {
		a[i] = b[i - start];
	}

}

void sort(int start, int end) {
	if (start == end) {
		return;
	}
	int mid = (start + end) / 2;
	sort(start, mid);
	sort(mid + 1, end);
	merge(start, end);
}

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(0, n - 1);
	printf("%ld\n", ans);
	return 0;
}
