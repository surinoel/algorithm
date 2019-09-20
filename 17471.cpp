#include <cmath>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int person[10];
vector<int> mat[10];
bool checka[10], checkb[10];
bool visita[10], visitb[10];

void go1(int idx) {
	if (visita[idx]) {
		return;
	}
	visita[idx] = true;
	for (int i = 0; i < mat[idx].size(); i++) {
		int y = mat[idx][i];
		if (checka[y] && !visita[y]) {
			go1(y);
		}
	}
	return;
}

void go2(int idx) {
	if (visitb[idx]) {
		return;
	}
	visitb[idx] = true;
	for (int i = 0; i < mat[idx].size(); i++) {
		int y = mat[idx][i];
		if (checkb[y] && !visitb[y]) {
			go2(y);
		}
	}
	return;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> person[i];
	}
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		for (int j = 0; j < num; j++) {
			int x;
			cin >> x;
			mat[i].push_back(x - 1);
		}
	}

	int ans = -1;
	for (int i = 1; i < (1 << n) - 1; i++) {
		vector<int> a, b;
		memset(checka, false, sizeof(checka));
		memset(checkb, false, sizeof(checkb));
		memset(visita, false, sizeof(visita));
		memset(visitb, false, sizeof(visitb));
		
		int suma = 0, sumb = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				a.push_back(j);
				suma += person[j];
				checka[j] = true;
			}
			else {
				b.push_back(j);
				sumb += person[j];
				checkb[j] = true;
			}
		}

		go1(a[0]);
		bool ok = true;
		for (int j = 0; j < a.size(); j++) {
			if (!visita[a[j]]) {
				ok = false;
				break;
			}
		}
		if (!ok) continue;

		go2(b[0]);
		for (int j = 0; j < b.size(); j++) {
			if (!visitb[b[j]]) {
				ok = false;
				break;
			}
		}
		if (!ok) continue;

		int diff = abs(suma - sumb);
		if (ans == -1 || ans > diff) {
			ans = diff;
		}
	}

	cout << ans << '\n';
	return 0;
}
