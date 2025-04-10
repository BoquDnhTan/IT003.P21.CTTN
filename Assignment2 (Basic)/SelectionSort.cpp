#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200 + 5;

int n;
int a[MAX_N];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i < n; i++) {
		int mnPos = i + 1;
		for (int j = i + 2; j <= n; j++) {
			if (a[j] < a[mnPos]) {
				mnPos = j;
			}
		}
		if (a[i] > a[mnPos]) {
			swap(a[i], a[mnPos]);
			for (int k = 1; k <= n; k++) {
				cout << a[k] << ' ';
			}
			cout << '\n';
		}
	}

	return 0;
}

/*


*/