#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{    
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif    

    int t;
    cin >> t;
    while(t--)
    {
        int n,s;
		cin >> n >> s;
		int ans = s/n;
		ans *=2;
		cout << ans << '\n';

     
        
    }

}
