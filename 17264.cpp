#include <map>
#include <string>
#include <iostream>

using namespace std;

map<string, int> hackplayer;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, p, W, L, G;
	cin >> n >> p >> W >> L >> G;
	for (int i = 0; i < p; i++) {
		string s, w;
		cin >> s >> w;
		if (w == "W") {
			hackplayer[s] = 1;
		}
		else {
			hackplayer[s] = 0;
		}
	}

	int sum = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (hackplayer.count(s) && hackplayer[s] == 1) {
			sum += W;
			if (sum >= G) {
				cout << "I AM NOT IRONMAN!!\n";
				return 0;
			}
		}
		else {
			sum -= L;
			if (sum <= 0) {
				sum = 0;
			}
		}
	}
	cout << "I AM IRONMAN!!\n";
	return 0;
}
