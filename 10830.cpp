#include <vector>
#include <iostream>

using namespace std;

int n;
long long m;
vector<vector<long long>> mat;
vector<vector<long long>> base;

vector<vector<long long>> mulmat(const vector<vector<long long>> &mat1, const vector<vector<long long>> &mat2) {
	vector<vector<long long>> tmp(n, vector<long long>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				tmp[i][j] += ((mat1[i][k] % 1000) * (mat2[k][j] % 1000)) % 1000;
			}
		}
	}
	return tmp;
}

vector<vector<long long>> go(const vector<vector<long long>>& a, long long b) {
	if (b == 0) {
		return base;
	}
	else if (b == 1) {
		return a;
	}

	if (b % 2 == 0) {
		vector<vector<long long>> tmp = go(a, b / 2);
		return mulmat(tmp, tmp);
	}
	else {
		return mulmat(a, go(a, b - 1));
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
  
	cin >> n >> m;
	mat.resize(n, vector<long long>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}
	base.resize(n, vector<long long>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) base[i][j] = 1;
		}
	}

	vector<vector<long long>> ans = go(mat, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j] % 1000 << ' ';
		}
		cout << '\n';
	}
	return 0;
}
