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

	for (int i = 2; i <= n; i++) {
		int key = a[i];
		int j = i - 1;
		while (j && a[j] >= key) {
			a[j + 1] = a[j];
			for (int z = 1; z <= n; z++) {
				cout << a[z] << ' ';
			}
			cout << '\n';
			j--;
		}
		a[j + 1] = key;
		for (int z = 1; z <= n; z++) {
			cout << a[z] << ' ';
		}
		cout << '\n';
	}

	return 0;
}

/*


*/