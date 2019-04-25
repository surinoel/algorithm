#include <map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string a;
	int k;
	cin >> a >> k;
	bool ok = true;
	map<string, int> m;
	vector<string> v;
	v.push_back(a);
	int ans;
	while (true) {
		if (!m.count(a)) {
			m[a] = 1;
		}
		else {
			for (int i = 0; i < v.size(); i++) {
				if (v[i] == a) {
					ans = i;
					ok = false;
					break;
				}
			}
		}
		
		if (!ok) break;

		long long sum = 0;
		for (int i = 0; i < a.size(); i++) {
			long long tmp = 1;
			for (int j = 0; j < k; j++) {
				tmp *= (a[i] - '0');
			}
			sum += tmp;
		}

		a = to_string(sum);
		v.push_back(a);
	}

	cout << ans << '\n';
	return 0;
}
