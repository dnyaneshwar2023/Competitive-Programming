#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{	
	#ifndef ONLINE_JUDGE
    	
        freopen("input6.txt","w",stdout);
	#endif	

    srand(time(0));

    int t = rand()%1000 + 1;
    cout << t << '\n';
    while(t--)
    {
        int n = rand()%100 + 1;
        int k = rand()%1000 + 1;
        cout << n << ' ' << k << '\n';
        for(int i=0;i<n;i++)
        {
            int x = rand()%1000 + 1;
            cout << x << ' ';
        }
        cout << '\n';

    }


}
