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

	for (int i = n; i; i--) {
		for (int j = 1; j < i; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				for (int z = 1; z <= n; z++) {
					cout << a[z] << ' ';
				}
				cout << '\n';
			}
		}
	}

	return 0;
}

/*


*/