#include <iostream>
#include <vector>
using namespace std;
 
int main() {
	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int& i : a)
			cin >> i;
		long long ans0 = 0;
		for (int i = 1; i < n; i++)
			ans0 += abs(a[i] - a[i - 1]);
		long long ans = ans0 - max(abs(a[1] - a[0]), abs(a[n - 1] - a[n - 2]));
		for (int i = 2; i < n; i++) {
			ans = min(ans, ans0
				- abs(a[i - 0] - a[i - 1])
				- abs(a[i - 1] - a[i - 2])
				+ abs(a[i - 0] - a[i - 2]));
		}
		cout << ans << endl;
	}
	return 0;
}

