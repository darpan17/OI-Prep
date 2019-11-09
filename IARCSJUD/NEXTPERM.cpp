#include <bits/stdc++.h>

#define FOR(i,n) for(int i = 0; i < n; i++)
#define FORE(i,a,b) for(int i = a; i <= b; i++)
#define pb push_back
#define ll long long

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	#endif
	int n,k; cin >> n >> k;
	vector<int> a;
	int x;
	FOR(i,k){
		a.clear();
		FOR(j,n){
			cin >> x;
			a.pb(x);
		}
		next_permutation(a.begin(),a.end());
		for(auto j:a)cout << j << " ";
		cout << "\n";
	}
	return 0;
}
