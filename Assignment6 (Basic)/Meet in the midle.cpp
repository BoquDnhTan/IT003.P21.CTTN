#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define pill pair<int, ll>
#define plli pair<ll, int>
#define pii pair<int, int>
#define pll pair<ll, ll>
 
const int MAX_N = 20 + 5;
const ll mod = 1e9 + 7; // 998244353
const ll inf = 1e18 + 1;
 
int n, m;
ll x;
int a[MAX_N];
int b[MAX_N];
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	cin >> n >> x;
	m = n / 2;
	n -= m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
 
	vector<ll> left, right;
 
	for (int mask = 0; mask < (1 << n); mask++) {
		ll sum = 0;
		for (int j = 0; j < n; j++) {
			if ((mask >> j) & 1) {
				sum += a[j];
			}
		}
		left.emplace_back(sum);
	}
 
	for (int mask = 0; mask < (1 << m); mask++) {
		ll sum = 0;
		for (int j = 0; j < m; j++) {
			if ((mask >> j) & 1) {
				sum += b[j];
			}
		}
		right.emplace_back(sum);
	}
 
	sort(left.begin(), left.end());
	sort(right.begin(), right.end());
 
	ll ans = 0;
	for (auto it : left) {
		// it + ?? = x <=> ?? = x - it
		int leftPos = lower_bound(right.begin(), right.end(), x - it) - right.begin();
		int rightPos = upper_bound(right.begin(), right.end(), x - it) - right.begin();
		ans += rightPos - leftPos;
	}
 
	cout << ans;
 
	return 0;
}
