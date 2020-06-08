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
    	vector<pll> photo(n);
    	vector<ll> frame(m);
    	F0R(i, n) cin >> photo[i].S >> photo[i].F;
    	F0R(i, m) cin >> frame[i];
    	sort(photo.begin(), photo.end());
    	sort(frame.begin(), frame.end());
    	int ans = 0;
    	int pidx = n - 1, fidx = m - 1;
    	while(pidx >= 0 && fidx >= 0) {
    		if(frame[fidx] >= photo[pidx].S) ans++, pidx--, fidx--;
    		else pidx--;
    	}
    	cout << ans;
    }
