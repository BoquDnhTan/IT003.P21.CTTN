#include <bits/stdc++.h>

using namespace std;

template<class A, class B> bool maximize(A& x, B y) {if (x < y) return x = y, true; else return false;}
template<class A, class B> bool minimize(A& x, B y) {if (x > y) return x = y, true; else return false;}

#define     all(a)                a.begin(), a.end()
#define     pb                    push_back
#define     pf                    push_front
#define     fi                    first
#define     se                    second
// #define     int                   long long

typedef     long long             ll;
typedef     unsigned long long    ull;
typedef     double                db;
typedef     long double           ld;
typedef     pair<db, db>          pdb;
typedef     pair<ld, ld>          pld;
typedef     pair<int, int>        pii;
typedef     pair<ll, ll>          pll;
typedef     pair<ll, int>         plli;
typedef     pair<int, ll>         pill;

const int MAX_N = 1e5 + 5;

int n;
int a[MAX_N];

void sapxep(int l, int r) {
	if (l >= r) {
		return;
	}

	int mid = (l + r) >> 1;

	sapxep(l, mid);
	sapxep(mid + 1, r);

	vector<int> leftList(a + l, a + mid + 1), rightList(a + mid + 1, a + r + 1);

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
		cin >> a[i];
	}

	sapxep(1, n);

	int mex = 0;
	for (int i = 1; i <= n; i++) {
		mex += (mex == a[i]);
	}

	cout << mex;

	return 0;
}

/*


*/