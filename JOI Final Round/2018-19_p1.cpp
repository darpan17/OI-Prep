    #include <bits/stdc++.h>
     
    #define ll long long int
    #define pll pair<ll, ll>
    #define F first
    #define S second
    #define mp make_pair
    #define pb push_back
    #define F0R(i, n) for(auto i = 0; i < (n); i++)
    #define FOR(i, a, b) for(auto i = (a); i <= (b); i++)
    #define ROF(i, a, b) for(auto i = (a); i >= (b); i--)
     
    using namespace std;
     
    int main()
    {
    	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    	int n, m; cin >> n >> m;
    	string a[n]; F0R(i, n) cin >> a[i];
    	int preo[n + 5][m + 5], prei[n + 5][m + 5];
    	memset(preo, 0, sizeof(preo));
    	memset(prei, 0, sizeof(prei));
    	F0R(i, n) {
    		ROF(j, m - 1, 0) {
    			preo[i][j] = preo[i][j + 1] + (a[i][j] == 'O');
    		}
    	}
    	F0R(j, m) {
    		ROF(i, n - 1, 0) {
    			prei[i][j] = prei[i + 1][j] + (a[i][j] == 'I');
    		}
    	}
    	ll ans = 0;
    	F0R(i, n) {
    		F0R(j, m) {
    			if(a[i][j] == 'J') {
    				ans += prei[i][j] * preo[i][j];
    			}
    		}
    	}
    	cout << ans;
    }
