
#include <bits/stdc++.h>
using namespace std;


int N;

int count_distinct(const vector<string>& ids){
	map<string,int> Hash; 
	
    for (auto it : ids) {
        Hash[it]++;
    }
    return Hash.size();
}

int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	cin >> N;
	vector<string> ids(N);
	
	for (int i = 0; i < N; i++) cin >> ids[i];
		
	cout << count_distinct(ids);

	return 0;
}

