#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<int> g[100005];
int in[100005];
int low[100005];
int vis[100005];
int marked[100005];
int timer;
void dfs(int u,int par = -1)
{
	vis[u] = 1;
	in[u] = low[u] = timer++;
	int children = 0;
	for(auto v:g[u])
	{
		if(v == par)
			continue;
		if(vis[v])
		{

			low[u] = min(low[u],in[v]);
		}
		else
		{
			dfs(v,u);
			if(low[v] >= in[u] && par != -1)
				marked[u] = 1;
			low[u] = min(low[u],low[v]);
			children++;

		}
	}

	if(par == -1 && children > 1)
		marked[u] = 1;

}
signed main()
{
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
	int n,m;
	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin >> a >> b;
		g[a].push_back(b);	
		g[b].push_back(a);
	}

	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
			dfs(i);
	}

	int flag = 0;

	vector<int> points;


	for(int i=1;i<=n;i++)
	{
		if(marked[i])points.push_back(i);
	}



	if(points.size() == 0)
	{
		cout << "This is biconnected graph";
	}
	else
	{
		cout << "This is not binconnected graph\nArticulation Points:\n";
		for(int i:points)cout << i << ' ';
	}

	return 0;
}