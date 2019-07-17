#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

int n;
long long m;
long long** mat;
long long** base;
long long** ans;

long long **mulmat(long long **mat1, long long **mat2, int len){
	long long** tmp = (long long**)calloc(n, sizeof(long long*));
	for (int i = 0; i < len; i++) {
		tmp[i] = (long long*)calloc(n, sizeof(long long));
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				tmp[i][j] += ((mat1[i][k] % 1000) * (mat2[k][j] % 1000)) % 1000;
			}
		}
	}

	return tmp;
}

long long **go(long long **a, long long b){
	if (b == 0) {
		return base;
	}
	else if (b == 1) {
		return a;
	}

	if (b % 2 == 0) {
		long long** tmp = go(a, b / 2);
		return mulmat(tmp, tmp, n);
	}
	else {
		return mulmat(a, go(a, b - 1), n);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	mat = (long long**)calloc(n, sizeof(long long *));
	for (int i = 0; i < n; i++) {
		mat[i] = (long long*)calloc(n, sizeof(long long));
	}
	base = (long long**)calloc(n, sizeof(long long *));
	for (int i = 0; i < n; i++) {
		base[i] = (long long*)calloc(n, sizeof(long long));
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) base[i][j] = 1;
		}
	}

	ans = go(mat, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j] % 1000 << ' ';
		}
		cout << '\n';
	}
	return 0;
}
view raw
