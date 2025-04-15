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

struct Node {
	int data;
	int pos;
	Node* left;
	Node* right;
	Node (int _data) {
		data = _data;
		left = nullptr;
		right = nullptr;
	}
};

int n;
const int MAX_N = 2e6 + 10;
const int base = 1e6;
pii a[MAX_N];

void insertNode(Node* &root, int data, int pos = 0, int dist = 1) {
	if (!root) {
		int i = pos + base;
		if (a[i].se == dist) {
			maximize(a[i].fi, data);
		}
		else {
			if (!a[i].fi || a[i].se > dist) {
				a[i] = {data, dist};
			}
		}
		root = new Node(data);
		return;
	}

	if (data <= root->data) {
		insertNode(root->left, data, pos - 1, dist + 1);
	}
	else {
		insertNode(root->right, data, pos + 1, dist + 1);
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	Node* root = nullptr;

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		insertNode(root, x);
	}

	vector<int> ansList;
	for (int i = 0; i < MAX_N; i++) {
		if (a[i].fi) {
			ansList.pb(a[i].fi);
		}
	}
	sort(all(ansList));

	for (int& x : ansList) {
		cout << x << ' ';
	}

	return 0;
}

/*


*/