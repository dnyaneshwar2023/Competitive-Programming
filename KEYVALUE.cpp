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
        int n;
        cin >> n;
        map<int,vector<int>> mp;
        int sum = 0;
        int a[n];

        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            sum+=a[i];
        }

        for(int i=0;i<n;i++)
        {
            int s = a[i]*n;
            int d = abs(sum-s);
            mp[d].push_back(i+1);
        }

        auto it = mp.begin();

        cout << it->second.size() << '\n';

        for(int i=0;i<it->second.size();i++)
        {
            cout << it->second[i] << ' ';
        }
        cout << '\n';
        
    }

}
