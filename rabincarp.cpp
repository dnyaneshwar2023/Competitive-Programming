#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1000000007;
int Hash[1000005];
int power(int a,int b)
{
    if(b == 0)return 1;

    int ans = 1;
    while(b > 0)
    {
       
        if(b%2)
            ans = (ans*a)%mod;
        a = (a*a)%mod;

        b/=2;

    }
    return ans;
}
int get(int l,int r)
{
    // Modulo Inverse - Fermat Theorem
    return ((Hash[r] - Hash[l-1] + mod)*power(power(131,l-1),mod-2))%mod;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    string a,b;
    cin >> a >> b;
    int x = 131;
    long long hash = 0;
    for(int i=0;i<b.length();i++)
    {
        hash = (hash + x*(b[i]-'a'+1))%mod;
        x*=131;
        x%=mod;

    }
    x = 131;
    for(int i=0;i<a.length();i++)
    {
        Hash[i+1] = (Hash[i] + x*(a[i]-'a'+1))%mod;
        x*=131;
        x%=mod;
    }

    int l = b.length();

    int count = 0;

    for(int i=1;i + l - 1 <=a.length();i++)
    {
        int u = i;
        int v = i + l - 1;
        int hsh = get(u,v);
        if(hash == hsh)
            count++;

    }
    cout << count;
    return 0;
}