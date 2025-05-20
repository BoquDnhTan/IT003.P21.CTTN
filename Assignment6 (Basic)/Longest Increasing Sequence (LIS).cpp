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
const int mod = 1e9 + 7;
const ll inf = 1e18;

int n;
int a[MAX_N];
int dp[MAX_N];
int trc[MAX_N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    int ansPos = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[j] < a[i] && maximize(dp[i], dp[j] + 1)) {
                trc[i] = j;
            }
        }
        if (maximize(ans, dp[i])) {
            ansPos = i;
        }
    }

    cout << ans << '\n';
    vector<int> lis;
    while (ansPos) {
        lis.pb(a[ansPos]);
        ansPos = trc[ansPos];
    }

    reverse(all(lis));
    for (int x : lis) {
        cout << x << ' ';
    }

    return 0;
}

/*


Tuesday, 13 May 2025
13:07:48
*/