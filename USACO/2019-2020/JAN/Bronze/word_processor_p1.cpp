#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("word.in","r",stdin);
    freopen("word.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,k; cin >> n >> k;
    string a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int ci = 0,spaces = 0;
    string temp = "";
    while(ci < n)
    {
        if((int)(a[ci].size()+temp.size()-spaces) > k)
        {
            temp.pop_back();
            cout << temp << "\n";
            spaces = 1;
            temp = a[ci]+" ";
            ci++;
        }
        else
        {
            temp += a[ci];
            temp += " ";
            ci++;
            spaces++;
        }
    }
    if(!temp.empty())
    {
        temp.pop_back();
        cout << temp << "\n";
    }
}
