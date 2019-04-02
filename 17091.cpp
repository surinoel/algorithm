#include <iostream>
#include <string>

using namespace std;

string h[14] = { " ", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen" };
string m[31] = { " ", "one minute", "two minutes", "three minutes", "four minutes", "five minutes", "six minutes", "seven minutes", "eight minutes", "nine minutes", "ten minutes", "eleven minutes", "twelve minutes", "thirteen minutes", "fourteen minutes", "quarter",
"sixteen minutes", "seventeen minutes", "eighteen minutes", "nineteen minutes", "twenty minutes", "twenty one minutes", "twenty two minutes", "twenty three minutes", "twenty four minutes", "twenty five minutes", "twenty six minutes", "twenty seven minutes",
"twenty eight minutes", "twenty nine minutes", "half" };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int hour, min;
	cin >> hour >> min;

	string ans;
	if (min == 0) {
		ans = h[hour] + " o' clock";
	}
	else if (min >= 1 && min <= 30) {
		ans = m[min] + " past " + h[hour];
	}
	else {
		min = 60 - min;
		ans = m[min] + " to " + h[hour + 1];
	}
	cout << ans << '\n';
		
	return 0;
}