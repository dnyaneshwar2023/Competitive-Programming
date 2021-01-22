#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1000000000000;
string s[55];
int n,m;
char a[3]={'F','O','P'};
int X[8]={1,-1,0,0,1,1,-1,-1};
int Y[8]={0,0,1,-1,-1,1,1,-1};
void fill(int x,int y,char old,char nw)
{
	if(x<0 || y<0 || x>=n || y>=m || s[x][y]!=old)return;
	s[x][y] = nw;
	for(int i=0;i<8;i++)
	{
		fill(x+X[i],y+Y[i],old,nw);
	}	
}
void dfs(int x,int y,int& holes)
{
	if(x<0 || y<0 || x>=n || y>=m)return;

	if(s[x][y] == '1')
	{
		s[x][y] = 'W';
		for(int i=0;i<8;i++)
			dfs(x+X[i],y+Y[i],holes);
	}
	else if(s[x][y] == '.')
	{

		holes++;
		fill(x,y,'.','B');
	}
}
signed main()
{
	#ifndef ONLINE_JUDGE
            freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);
    #endif
	
    cin >> n >> m;
    for(int i=0;i<n;i++)cin >> s[i];
    string ans;
    fill(0,0,'.','B');
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(s[i][j] == '1')
			{
				int holes = 0;
				dfs(i,j,holes);
				ans+=a[holes];
			}
		}
	}

	sort(ans.begin(),ans.end());
	if(ans.length() == 0)
	{
		cout << "N\n";
	}
	else{
		cout << ans << '\n';
	}






	return 0;
}