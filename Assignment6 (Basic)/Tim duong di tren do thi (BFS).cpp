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

int n, m;
string a[MAX_N];
map<string, int> id;
vector<int> adj[MAX_N];
int trc[MAX_N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        id[a[i]] = i;
    }
    for (int i = 1; i <= m; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        adj[id[s1]].pb(id[s2]);
    }

    int q;
    cin >> q;
    while (q--) {
        string s1, s2;
        cin >> s1 >> s2;
        int u = id[s1], v = id[s2];
        queue<int> q;
        q.push(u);
        for (int i = 1; i <= n; i++) {
            trc[i] = -1;
        }
        trc[u] = 0;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int y : adj[x]) {
                if (trc[y] == -1) {
                    q.push(y);
                    trc[y] = x;
                }
            }
        }
        if (~trc[v]) {
            vector<int> path;
            while (v != u) {
                path.pb(v);
                v = trc[v];
            }
            path.pb(u);
            reverse(all(path));
            for (int x : path) {
                cout << a[x] << ' ';
            }
            cout << "\n";
        } else {
            cout << "no_path\n";
        }
    }

    return 0;
}

/*


Tuesday, 13 May 2025
13:41:32
*/