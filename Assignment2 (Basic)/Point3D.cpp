#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5 + 5;

int n;
struct Point {
	int x, y, z;

	bool operator < (const Point& other) const {
		if (x != other.x) {
			return x < other.x;
		}
		if (y != other.y) {
			return y > other.y;
		}
		return z < other.z;
	}
};

Point a[MAX_N];

void sapxep(int l, int r) {
	if (l >= r) {
		return;
	}

	int mid = (l + r) >> 1;

	sapxep(l, mid);
	sapxep(mid + 1, r);

	vector<Point> leftList(a + l, a + mid + 1), rightList(a + mid + 1, a + r + 1);

	int i = 0, j = 0;
	while (i < (int) leftList.size() && j < (int) rightList.size()) {
		if (leftList[i] < rightList[j]) {
			a[l++] = leftList[i++];
		}
		else {
			a[l++] = rightList[j++];
		}
	}
	while (i < (int) leftList.size()) {
		a[l++] = leftList[i++];
	}
	while (j < (int) rightList.size()) {
		a[l++] = rightList[j++];
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].y >> a[i].z;
	}

	sapxep(1, n);

	for (int i = 1; i <= n; i++) {
		cout << a[i].x << ' ' << a[i].y << ' ' << a[i].z << '\n';
	}

	return 0;
}

/*


*/