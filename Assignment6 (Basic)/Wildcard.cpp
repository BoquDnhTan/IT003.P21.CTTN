#include <bits/stdc++.h>
using namespace std;

template<class A, class B> bool maximize(A& x, B y) { return (x < y ? (x = y, true) : false); }
template<class A, class B> bool minimize(A& x, B y) { return (x > y ? (x = y, true) : false); }

#define all(a) a.begin(), a.end()
#define pb push_back

typedef long long ll;
typedef vector<int> vi;

int n, m;
int id[256];
string s;
int cnt[10001][10001];
int totalCnt[1000001];

struct TrieNode {
    int child[64]{};
};

struct Trie {
    vector<TrieNode> data;

    Trie() {
        data.pb(TrieNode());
    }
};

Trie forwardTrie, backwardTrie;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // Setup ID mapping
    for (char h = 'a'; h <= 'z'; h++) id[h] = h - 'a';
    for (char h = 'A'; h <= 'Z'; h++) id[h] = h - 'A' + 26;
    for (char h = '0'; h <= '9'; h++) id[h] = h - '0' + 52;
    id[' '] = 62;
    id['*'] = 63;

    cin >> n >> m;
    getline(cin, s); // consume the newline

    vector<string> strings(n + 1);
    for (int k = 1; k <= n; k++) {
        getline(cin, s);

        int p = 0;
        for (int i = 0; i < s.size(); i++) {
            if (!forwardTrie.data[p].child[id[s[i]]]) {
                forwardTrie.data[p].child[id[s[i]]] = forwardTrie.data.size();
                forwardTrie.data.pb(TrieNode());
            }
            p = forwardTrie.data[p].child[id[s[i]]];
            
            int p1 = 0;
            cnt[p][0]++;
            for (int j = s.size() - 1; j > i; j--) {
                if (!backwardTrie.data[p1].child[id[s[j]]]) {
                    backwardTrie.data[p1].child[id[s[j]]] = backwardTrie.data.size();
                    backwardTrie.data.pb(TrieNode());
                }
                p1 = backwardTrie.data[p1].child[id[s[j]]];
                cnt[p][p1]++;
            }
        }
        totalCnt[p]++;

        int p1 = 0;
        for (int j = s.size() - 1; j >= 0; j--) {
            if (!backwardTrie.data[p1].child[id[s[j]]]) {
                backwardTrie.data[p1].child[id[s[j]]] = backwardTrie.data.size();
                backwardTrie.data.pb(TrieNode());
            }
            p1 = backwardTrie.data[p1].child[id[s[j]]];
            cnt[0][p1]++;
        }
        cnt[0][0]++;
    }

    for (int i = 1; i <= m; i++) {
        getline(cin, s);
        int cntStar = count(all(s), '*');

        if (cntStar == 0) {
            int p = 0;
            for (int j = 0; j < s.size(); j++) {
                if (!forwardTrie.data[p].child[id[s[j]]]) {
                    p = -1;
                    break;
                }
                p = forwardTrie.data[p].child[id[s[j]]];
            }
            cout << (~p ? totalCnt[p] : 0) << '\n';
            continue;
        }


        if (s.size() == 1 && s[0] == '*') {
            cout << n << '\n';
            continue;
        }

        if (s[0] == '*') {
            s.erase(s.begin());
            int p = 0;
            for (int j = s.size() - 1; j >= 0; j--) {
                if (!backwardTrie.data[p].child[id[s[j]]]) {
                    p = -1;
                    break;
                }
                p = backwardTrie.data[p].child[id[s[j]]];
            }
            cout << (~p ? cnt[0][p] : 0) << '\n';
            continue;
        }

        if (s.back() == '*') {
            s.pop_back();
            int p = 0;
            for (int i = 0; i < s.size(); i++) {
                if (!forwardTrie.data[p].child[id[s[i]]]) {
                    p = -1;
                    break;
                }
                p = forwardTrie.data[p].child[id[s[i]]];
            }
            cout << (~p ? cnt[p][0] : 0) << '\n';
            continue;
        }

        // '*' in the middle
        int p = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                break;
            }
            if (!forwardTrie.data[p].child[id[s[i]]]) {
                p = -1;
                break;
            }
            p = forwardTrie.data[p].child[id[s[i]]];
        }
        if (~p) {
            int p1 = 0;
            for (int j = s.size() - 1; j > 0; j--) {
                if (s[j] == '*') {
                    break;
                }
                if (!backwardTrie.data[p1].child[id[s[j]]]) {
                    p1 = -1;
                    break;
                }
                p1 = backwardTrie.data[p1].child[id[s[j]]];
            }
            cout << (~p1 ? cnt[p][p1] : 0) << '\n';
        } else {
            cout << 0 << '\n';
        }
    }

    return 0;
}
