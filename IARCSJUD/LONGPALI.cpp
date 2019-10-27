#include <bits/stdc++.h>

#define FOR(i,n) for(int i = 0; i < n; i++)
#define FORE(i,a,b) for(int i = a; i <= b; i++)

using namespace std;

bool dp[5005][5005];

int main(){
    int n; cin >> n;
    string s; cin >> s;
    FOR(i,n) dp[i][i] = true;
    for(int i = n; i > 0; i--){
        FORE(j,i+1,n){
            // i to j is a palindrome or not
            if(s[i-1] == s[j-1]){
                if(j-i+1 == 2){
                    dp[i][j] = true;
                }else if(dp[i+1][j-1]){
                    dp[i][j] = true;
                }
            }
        }
    }
    int maxlen = 1;
    string ans;
    FORE(i,1,n){
        FORE(j,i,n){
            if(dp[i][j]){
                if(j-i+1 >= maxlen){
                    maxlen = j-i+1;
                    ans = s.substr(i-1,maxlen);
                }
            }
        }
    }
    cout << maxlen << "\n" << ans;
    return 0;
}
