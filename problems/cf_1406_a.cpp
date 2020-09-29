#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	int tests;
	cin >> tests;
	unordered_map<int, int> counts;
	for (int t = 0; t < tests; t++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			counts[a]++;
		}
		int m1 = 0, m2 = 0;
		bool foundM2 = false;
		while (true) {
			if (counts[m1] == 0) {
				break;
			}
			if (counts[m1] >= 2 && foundM2 == false) {
				m2++;
			}
			if (counts[m1] == 1) {
				foundM2 = true;
			}
			m1++;
		}
		cout << m1 + m2 << endl;
		counts.clear();
	}
	return 0;
}
