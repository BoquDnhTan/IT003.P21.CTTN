#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a;


vector<int> get_ans(const vector<int>& A,int K){
	map<int,int> Hash;
	vector<int> ans;

    for (int x : A) {
        Hash[x]++;
    }
    for (auto &it : Hash) {
        if (K > 0) {
            ans.push_back(it.first);
            it.second--;
            K--;
        }
    }
    for (auto &it : Hash) {
        while (K > 0 && it.second > 0) {
            ans.push_back(it.first);
            it.second--;
            K--;
        }
    }

    return ans;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	cin >> n >> k;
	
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	
	vector<int> ans = get_ans(a,k);
	
	for (const int& x: ans) cout << x << ' ';
	return 0;
}
