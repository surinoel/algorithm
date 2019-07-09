#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<string> v[2017];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	v[1967].push_back("DavidBowie");
	v[1969].push_back("SpaceOddity");
	v[1970].push_back("TheManWhoSoldTheWorld");
	v[1971].push_back("HunkyDory");
	v[1972].push_back("TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars");
	v[1973].push_back("AladdinSane");
	v[1973].push_back("PinUps");
	v[1974].push_back("DiamondDogs");
	v[1975].push_back("YoungAmericans");
	v[1976].push_back("StationToStation");
	v[1977].push_back("Low");
	v[1977].push_back("Heroes");
	v[1979].push_back("Lodger");
	v[1980].push_back("ScaryMonstersAndSuperCreeps");
	v[1983].push_back("LetsDance");
	v[1984].push_back("Tonight");
	v[1987].push_back("NeverLetMeDown");
	v[1993].push_back("BlackTieWhiteNoise");
	v[1995].push_back("1.Outside");
	v[1997].push_back("Earthling");
	v[1999].push_back("Hours");
	v[2002].push_back("Heathen");
	v[2003].push_back("Reality");
	v[2013].push_back("TheNextDay");
	v[2016].push_back("BlackStar");

	int tc;
	cin >> tc;
	while (tc--) {
		int a, b;
		cin >> a >> b;
		int cnt = 0;
		for (int i = a; i <= b; i++) {
			cnt += v[i].size();
		}
		if (cnt == 0) cout << 0 << '\n';
		else {
			cout << cnt << '\n';
			for (int i = a; i <= b; i++) {
				for (int j = 0; j < v[i].size(); j++) {
					cout << i << ' ' << v[i][j] << '\n';
				}
			}
		}
	}

	return 0;
}
