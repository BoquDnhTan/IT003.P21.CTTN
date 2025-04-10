#include <bits/stdc++.h>

using namespace std;

template<class A, class B> bool maximize(A& x, B y) {if (x < y) return x = y, true; else return false;}
template<class A, class B> bool minimize(A& x, B y) {if (x > y) return x = y, true; else return false;}

#define     all(a)                a.begin(), a.end()
#define     pb                    push_back
#define     pf                    push_front
#define     fi                    first
#define     se                    second
#define     int                   long long

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

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	string k;
	cin >> n;
	vector<string> a(n);
	for (auto &x : a) cin >> x;
	cin >> k;

	int numStep = 0;
	int pos = -1;

	int low = 0, high = n - 1;
	while (low <= high) {
		int mid = (low + high) >> 1;
		numStep++;

		if (a[mid] < k) {
			low = mid + 1;
		}
		else if (a[mid] > k) {
			high = mid - 1;
		}
		else {
			pos = mid;
			break;
		}
	}

	cout << pos;
	if (~pos) {
		cout << '\n' << numStep;
	}

	return 0;
}

/*


*/