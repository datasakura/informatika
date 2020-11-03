#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;
		vector<pair<int, int>> s(n);
		for (auto& i : s)
			cin >> i.first;
		for (auto& i : s)
			cin >> i.second;
 
		sort(s.begin(), s.end());
		long long sum = 0;
		for (auto& i : s)
			sum += i.second;
		long long ans = sum;
		for (auto& i : s) {
			sum -= i.second;
			ans = min(ans, max((long long) i.first, sum));
		}
 
		cout << ans << endl;
	}
	return 0;
}
