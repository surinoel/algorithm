#include <string>
#include <cstring>
#include <iostream>

using namespace std;

typedef struct __pb {
	string s;
	int stk, ball;
} PB;

PB pb[100];
int num_cnt[10];
bool cipher_check[3];
bool cipher_cmp_check[3];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> pb[i].s >> pb[i].stk >> pb[i].ball;
	}
	int ans = 0;
	for (int num = 100; num < 1000; num++) {
		bool ok = true;
		string snum = to_string(num);
		memset(num_cnt, 0, sizeof(num_cnt));
		num_cnt[snum[0] - '0'] += 1;
		num_cnt[snum[1] - '0'] += 1;
		num_cnt[snum[2] - '0'] += 1;
		if (num_cnt[snum[0] - '0'] > 1 || num_cnt[snum[1] - '0'] > 1 || num_cnt[snum[2] - '0'] > 1) {
			ok = false;
		}
		if (snum[0] == '0' || snum[1] == '0' || snum[2] == '0') {
			ok = false;
		}	
		if (ok) {
			for (int i = 0; i < n; i++) {
				int stk, ball;
				stk = ball = 0;
				string cmpnum = pb[i].s;
				memset(cipher_check, false, sizeof(cipher_check));
				memset(cipher_cmp_check, false, sizeof(cipher_cmp_check));
				
				if (cmpnum[0] == snum[0]) {
					stk += 1;
					cipher_check[0] = true;
					cipher_cmp_check[0] = true;
				}
				if (cmpnum[1] == snum[1]) {
					stk += 1;
					cipher_check[1] = true;
					cipher_cmp_check[1] = true;
				}
				if (cmpnum[2] == snum[2]) {
					stk += 1;
					cipher_check[2] = true;
					cipher_cmp_check[2] = true;
				}
				if (!cipher_check[0]) {
					if (!cipher_cmp_check[1] && (cmpnum[0] == snum[1])) {
						ball += 1;
						cipher_check[0] = true;
						cipher_cmp_check[1] = true;
					}
					else if (!cipher_cmp_check[2] && (cmpnum[0] == snum[2])) {
						ball += 1;
						cipher_check[0] = true;
						cipher_cmp_check[2] = true;
					}
				}
				if (!cipher_check[1]) {
					if (!cipher_cmp_check[0] && (cmpnum[1] == snum[0])) {
						ball += 1;
						cipher_check[1] = true;
						cipher_cmp_check[0] = true;
					}
					else if (!cipher_cmp_check[2] && (cmpnum[1] == snum[2])) {
						ball += 1;
						cipher_check[1] = true;
						cipher_cmp_check[2] = true;
					}
				}
				if (!cipher_check[2]) {
					if (!cipher_cmp_check[0] && (cmpnum[2] == snum[0])) {
						ball += 1;
						cipher_check[2] = true;
						cipher_cmp_check[0] = true;
					}
					else if (!cipher_cmp_check[1] && (cmpnum[2] == snum[1])) {
						ball += 1;
						cipher_check[2] = true;
						cipher_cmp_check[1] = true;
					}
				}
		
				if (!(stk == pb[i].stk && ball == pb[i].ball)) {
					ok = false;
					break;
				}
			}
		}
		if (ok) {
			ans += 1;
		}
	}

	cout << ans << '\n';
	return 0;
}
