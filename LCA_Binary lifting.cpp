#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int maxN=20;
int dp[200005][maxN];
int mx[200005][maxN];
vector<int>g[200005];
int level[200005];

int n;

void dfs(int u,int par = -1)
{
    dp[u][0] = par;
    if(par!=-1)
    mx[u][0] = max(a[u],dp[par][0]);
    else dp[u][0] = a[u];
    if(par!=-1)
    level[u] = level[par] + 1;
    for(auto v:g[u])
    {
        if(v==par)continue;
        dfs(v,u);
    }
}

void process()
{
    memset(dp,-1,sizeof dp);
    dfs(1,-1);
    for(int j=1;j<maxN;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(dp[i][j-1]!=-1)
            {
                int p = dp[i][j-1];
                dp[i][j] = dp[p][j-1];
                mx[i][j] = max(mx[i][j],mx[p][j-1]);
            }
        }
    }
}
int getLCA(int a,int b)
{
    if(level[a] > level[b])swap(a,b);

    int d = level[b]-level[a];

    while(d>0)
    {
        int i = log2(d);
        b = dp[b][i];
        d-=(1<<i);
    }

    if(a==n)return a;

    for(int i=maxN-1;i>=0;i--)
    {
        if(dp[a][i]!=-1 && dp[a][i]!=dp[b][i])
            a=dp[a][i],b=dp[b][i];
    }

    return dp[a][0];

}

signed main()
{

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    cin >> n;

    for(int i=0;i<n-1;i++)
    {
        int a,b;cin >> a >> b;
        g[a].push_back(b);
    }
    
    process();


    cout << getLCA(3,5) << '\n';









    
}