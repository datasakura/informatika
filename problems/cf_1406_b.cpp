#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int tests;
	cin >> tests;
	for (int t = 0; t < tests; t++) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int& i : a)
			cin >> i;

		long long ans = 1ll * a[0] * a[1] * a[2] * a[3] * a[4];
		if (ans < 0) {
			for (int i : a) {
				if (i == 0)
					ans = 0;
			}
		}

		vector<int> pos, neg;
		for (int i : a) {
			if (i > 0)
				pos.push_back(i);
			if (i < 0)
				neg.push_back(i);
		}
		sort(pos.begin(), pos.end());
		sort(neg.begin(), neg.end());
		reverse(pos.begin(), pos.end());
		if (pos.size() >= 5) {
			long long ans2 = 1ll * pos[0] * pos[1] * pos[2] * pos[3] * pos[4];
			ans = max(ans, ans2);
		}
		if (pos.size() >= 3 && neg.size() >= 2) {
			long long ans2 = 1ll * pos[0] * pos[1] * pos[2] * neg[0] * neg[1];
			ans = max(ans, ans2);
		}
		if (pos.size() >= 1 && neg.size() >= 4) {
			long long ans2 = 1ll * pos[0] * neg[0] * neg[1] * neg[2] * neg[3];
			ans = max(ans, ans2);
		}
		reverse(neg.begin(), neg.end());
		if (neg.size() >= 5) {
			long long ans2 = 1ll * neg[0] * neg[1] * neg[2] * neg[3] * neg[4];
			ans = max(ans, ans2);
		}
		cout << ans << endl;
	}
}
