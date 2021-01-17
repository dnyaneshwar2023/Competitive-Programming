#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 100000000000;
int dp[100005][20];
vector<pair<int,int>> g[100001];
void dijkstra(int s,int n,int t) {
    memset(dp,-1,sizeof dp);
    dp[s][0]=0;

    using pii = pair<int,pair<int,int>>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0,{s,0}});

    while (!q.empty()) {
        int v = q.top().second.first;
        int token = q.top().second.second;
        int d_v = dp[v][token];
        q.pop();
        for(auto edge:g[v])
        {
            int to = edge.first;
            int w  = edge.second;

            if(to == v)
                continue;
            
            int ccst = d_v + w;

            if(dp[to][token] == -1)
            {
                q.push({-1*ccst,{to,token}});
                dp[to][token] = ccst;
            }
            else if(dp[to][token] > ccst)
            {
                q.push({-1*ccst,{to,token}});
                dp[to][token] = ccst;
            }

            ccst = d_v;
            if(token == t)
                continue;
            if(dp[to][token + 1] == -1)
            {
                q.push({-1*ccst,{to,token + 1}});
                dp[to][token + 1] = ccst;
            }
            else if(dp[to][token + 1] > ccst)
            {
                q.push({-1*ccst,{to,token+1}});
                dp[to][token + 1] = ccst;
            }

            
        }
    }
}

signed main()
{
    #ifndef ONLINE_JUDGE
            freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);
    #endif

    int n,m,k;
    cin >> n >> m >> k;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dijkstra(1,n,k);

    for(int i=1;i<=n;i++)
    {
        int mini = 10000000000;
        for(int j=0;j<=k;j++)
        {
            if(dp[i][j]!=-1)
            {
                mini = min(mini,dp[i][j]);
            }
        }
        cout << mini << ' ';
    }
    
    

}