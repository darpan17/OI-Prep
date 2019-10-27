#include <bits/stdc++.h>

#define FOR(i,n) for(int i = 0; i < n; i++)
#define FORE(i,a,b) for(int i = a; i <= b; i++)
#define pb push_back

using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vector<string> inp(n); 
	cin.ignore();
	FOR(i,n){ 
	    getline(cin,inp[i]);
	}
	vector<string> ans(n);
	string temp;
	FOR(i,n){
		for(int j = inp[i].size()-1; j >= 0; j--){
			if(inp[i][j] == ' '){
			    if(temp == "")continue;
				reverse(temp.begin(),temp.end());
				for(auto k:temp) ans[i].pb(k);
				ans[i].pb(' ');
				temp.clear();
			}else if((inp[i][j] >= 'A' && inp[i][j] <= 'Z') || (inp[i][j] >= 'a' && inp[i][j] <= 'z')){
			    temp.pb(inp[i][j]);
			}
			if(j == 0){
			    reverse(temp.begin(),temp.end());
				for(auto k:temp) ans[i].pb(k);
				ans[i].pb(' ');
				temp.clear();
			}
		}
	}
	for(int i = n-1; i >= 0; i--) cout << ans[i] << "\n";
	return 0;
}
