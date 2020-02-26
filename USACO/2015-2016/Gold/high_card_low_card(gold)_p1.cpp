#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("cardgame.in","r",stdin);
    freopen("cardgame.out","w",stdout);
    int n; scanf("%d",&n);
    bool taken[2*n+5];
    memset(taken,false,sizeof(taken));
    vector<int> fh,sh;
    int x;
    for(int i = 0; i < n; i++){
        scanf("%d",&x);
        taken[x] = true;
        if(i<n/2) fh.push_back(x);
        else sh.push_back(x);
    }
    sort(fh.begin(),fh.end());
    sort(sh.begin(),sh.end());
    int ans = 0;
    vector<int> rem1,rem2,rem;
    for(int i = 1; i <= 2*n; i++){
        if(!taken[i]){
            rem.push_back(i);
        }
    }
    for(int i = 0; i < rem.size(); i++){
        if(i<n/2) rem1.push_back(rem[i]);
        else rem2.push_back(rem[i]);
    }

    for(int i = 0; i < n/2; i++){
        int idx = upper_bound(rem2.begin(),rem2.end(),fh[i])-rem2.begin();
        if(idx == rem2.size()) break;
        rem2.erase(rem2.begin()+idx);
        ans++;
    }
    for(int i = n/2-1; i >= 0; i--){
        int idx = lower_bound(rem1.begin(),rem1.end(),sh[i])-rem1.begin();
        if(idx == 0) break;
        rem1.erase(rem1.begin()+(idx-1));
        ans++;
    }
    printf("%d",ans);
    return 0;
}
