#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> g[100005];
int in[100005];
int out[100005];
int timer;
void dfs(int u,int par=-1)
{
	in[u] = timer++;
	for(auto v:g[u])
	{
		if(v==par)
			continue;
		dfs(v,u);
	}
	out[u] = timer++;
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
    
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
    	int u,v;
    	cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }

    dfs(1); // 1 -- root

    int q;
    cin >> q;
    while(q--)
    {
    	int a,b;
    	cin >> a >> b;

    	if(in[a] < in[b] && out[a] > out[b])
    	{
    		cout << "YES\n";
    	}
    	else
    	{
    		cout << "NO\n";
    	}
    }


}