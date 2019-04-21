#include <vector>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int k; cin >> k;
	vector<pair<int, int>> shape(6);
	for (int i = 0; i < 6; i++) {
		cin >> shape[i].first >> shape[i].second;
	}
	
	int area = -1;
	int ans = -1;
	for (int i = 0; i < 6; i++) {
		int artmp = shape[i].second * shape[(i + 1) % 6].second;
		if (area == -1 || artmp > area) {
			area = artmp;
			ans = area - shape[(i + 3) % 6].second * shape[(i + 4) % 6].second;
		}
	}

	cout << ans * k << '\n';
	return 0;
}
