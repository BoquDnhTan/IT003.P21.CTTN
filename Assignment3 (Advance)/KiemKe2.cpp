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

const int MAX_N = 2e5 + 5;
const int mod = 1e9 + 7; // 998244353
const ll inf = 1e18 + 1;

int n;
string b[MAX_N];

struct Data {
	string key;
	int val;

	bool operator < (const Data& other) const {
		if (val == other.val) {
			if (key.size() == other.key.size()) {
				return key < other.key;
			}
			return key.size() < other.key.size();
		}
		return val > other.val;
	}
};

Data a[MAX_N];

void sapxep(int l, int r) {
	if (l >= r) {
		return;
	}

	int mid = (l + r) >> 1;

	sapxep(l, mid);
	sapxep(mid + 1, r);

	vector<Data> leftList(a + l, a + mid + 1), rightList(a + mid + 1, a + r + 1);

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

void sapxep2(int l, int r) {
	if (l >= r) {
		return;
	}

	int mid = (l + r) >> 1;

	sapxep2(l, mid);
	sapxep2(mid + 1, r);

	vector<string> leftList(b + l, b + mid + 1), rightList(b + mid + 1, b + r + 1);

	int i = 0, j = 0;
	while (i < (int) leftList.size() && j < (int) rightList.size()) {
		if (leftList[i] < rightList[j]) {
			b[l++] = leftList[i++];
		}
		else {
			b[l++] = rightList[j++];
		}
	}
	while (i < (int) leftList.size()) {
		b[l++] = leftList[i++];
	}
	while (j < (int) rightList.size()) {
		b[l++] = rightList[j++];
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	sapxep2(1, n);

	int m = 0;
	string currStr = "";
	int currCnt = 0;
	for (int i = 1; i <= n; i++) {
		if (b[i] != currStr) {
			if (currStr != "") {
				a[++m] = {currStr, currCnt};
			}

			currStr = b[i];
			currCnt = 1;
		}
		else {
			currCnt++;
		}
	}
	if (currStr != "") {
		a[++m] = {currStr, currCnt};
	}

	sapxep(1, m);
	for (int i = 1; i <= m; i++) {
		cout << a[i].key << ' ' << a[i].val << '\n';
	}

	return 0;
}

/*


*/