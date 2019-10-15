#include <string>
#include <iostream>

using namespace std;

int key[10];
pair<int, int> ap[] = {
	{2, 1}, {2, 2}, {2, 3},
	{3, 1}, {3, 2}, {3, 3},
	{4, 1}, {4, 2}, {4, 3},
	{5, 1}, {5, 2}, {5, 3},
	{6, 1}, {6, 2}, {6, 3},
	{7, 1}, {7, 2}, {7, 3}, {7, 4},
	{8, 1}, {8, 2}, {8, 3}, 
	{9, 1}, {9, 2}, {9, 3}, {9, 4}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 1; i <= 9; i++) {
		int x; 
		cin >> x;
		key[x] = i;
	}

	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		int y = s[i] - 'a';
		if (i - 1 >= 0 && ap[s[i - 1] - 'a'].first == ap[y].first) cout << "#";
		for (int j = 0; j < ap[y].second; j++) {
			cout << key[ap[y].first];
		}
	}
	cout << '\n';
	return 0;
}
