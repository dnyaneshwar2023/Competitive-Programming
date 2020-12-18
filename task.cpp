#include <bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
int n;
int ans;
vector<pair<int,int>> g[100001];
int dfs(int u,int par = -1)
{
	int child = 1;
	for(auto node:g[u])
	{

		int v = node.first;
		int w = node.second;

		if(v == par)
			continue;

		int k = dfs(v,u);
		ans += 2*min(k,n-k)*w;
		child += k;
	}
	return child;
}


int32_t main()
{
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
	int t;
	cin >> t;
	int cs = 1;
	while(t--)
	{
		for(int i=1;i<=100000;i++)g[i].clear();
		ans = 0;
		cin >> n;
		for(int i=1;i<n;i++)
		{
			int u,v,w;cin >> u >> v >> w;
			g[u].push_back({v,w});
			g[v].push_back({u,w});
		}
		dfs(1);
		cout << "Case #"<<cs++<<": ";
		cout << ans << '\n';

	}







	return 0;
}