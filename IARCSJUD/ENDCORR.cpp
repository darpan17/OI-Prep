#include <bits/stdc++.h>

#define FOR(i,n) for(int i = 0; i < n; i++)
#define FORE(i,a,b) for(int i = a; i <= b; i++)
#define ll long long

using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int n,m; cin >> n >> m;
	priority_queue<ll> pq;
	ll x;
	FOR(i,n+m){
		cin >> x;
		if(x == -1){
			cout << pq.top() << "\n";
			pq.pop();
		}else{
			pq.push(x);
		}
	}
	return 0;
}	
