#include <cmath>
#include <iostream>

using namespace std;

typedef long long ll;
int arr[1000000];
ll* tree;

long long init(int idx, int start, int end) {
	if (start == end) {
		return tree[idx] = arr[start];
	}
	else {
		return tree[idx] = init(2 * idx + 1, start, (start + end) / 2) +
			init(2 * idx + 2, (start + end) / 2 + 1, end);
	}
}

long long sum(int idx, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return 0;
	}
	else if (left <= start && end <= right) {
		return tree[idx];
	}
	else {
		int mid = (start + end) / 2;
		return sum(2 * idx + 1, start, mid, left, right) + 
			sum(2 * idx + 2, mid + 1, end, left, right);
	}
}

void change(int idx, ll diff, int start, int end, int changeidx) {
	if (start > changeidx || end < changeidx) return;

	tree[idx] += diff;
	if (start < end) {
		int mid = (start + end) / 2;
		change(2 * idx + 1, diff, start, mid, changeidx);
		change(2 * idx + 2, diff, mid + 1, end, changeidx);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;
	int h = (int)ceil(log2(n));
	int tree_size = 1 << (h + 1);

	tree = new ll[tree_size];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	init(0, 0, n - 1);
	for (int i = 0; i < m + k; i++) {
		int a, b;
		cin >> a >> b;
		b -= 1;
		if (a == 1) {
			ll c;
			cin >> c;
			ll diff = c - arr[b];
			change(0, diff, 0, n - 1, b);
			arr[b] = c;
 		}
		else {
			int c;
			cin >> c;
			c -= 1;
			cout << sum(0, 0, n - 1, b, c) << '\n';
		}
	}

	delete[] tree;
	return 0;
}
