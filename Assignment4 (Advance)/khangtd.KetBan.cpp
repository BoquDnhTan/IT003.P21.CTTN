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
const int mod = 1e9 + 7; // 998244353
const ll inf = 1e18 + 1;

int n, m;

struct Node {
	int id;
	Node* left;
	Node* right;
	Node(int _id) {
		id = _id;
		left = right = nullptr;
	}
};

Node* a[MAX_N];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		a[i] = new Node(i);
	}
	for (int i = 1; i <= n; i++) {
		a[i]->left = a[i - 1];
		a[i]->right = a[i + 1];
	}
	a[1]->left = a[n];
	a[n]->right = a[1];

	while (m--) {
		int x, y;
		cin >> x >> y;

		a[x]->left->right = a[x]->right;
		a[x]->right->left = a[x]->left;
		a[x]->left = a[y];
		a[x]->right = a[y]->right;
		a[x]->left->right = a[x];
		a[x]->right->left = a[x];
	}

	Node* p = a[1];
	for (int i = 1; i <= n; i++) {
		cout << p->id << ' ';
		p = p->right;
	}

	return 0;
}

/*


*/