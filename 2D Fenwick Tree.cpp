#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1001;
int fk[1002][1002];
int marked[1002][1002];

int INCR(int n)
{
	return (n & -n);
}

int  sum(int x,int y)
{
	int ans = 0;
	for(int i=x;i>0;i-=INCR(i))
	{
		for(int j=y;j>0;j-=INCR(j))
		{
			ans+=fk[i][j];
		}
	}
	return ans;
}

void update(int x,int y,int value)
{
	for(int i=x;i<=N;i+=INCR(i))
	{
		for(int j=y;j<=N;j+=INCR(j))
		{
			fk[i][j]+=value;
		}
	}

}
signed main()
{	
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
	#endif	

    int t;
    cin >> t;
    for(int cs=1;cs<=t;cs++)
    {
    	cout <<"Case " << cs <<":\n";
    	memset(marked,0,sizeof marked);
    	memset(fk,0,sizeof fk);

    	int q;
    	cin >> q;
    	while(q--)
    	{
    		int type;
    		cin >> type;
    		if(type == 0)
    		{
    			int x,y;cin >> x >> y;
    			x++;y++;
    			if(!marked[x][y])
    			{
    				marked[x][y] = 1;
    				update(x,y,1);
    			}
    		}
    		else
    		{
    			int x,y,xx,yy;

    			cin >> x >> y >> xx >> yy;
    			x++;y++;xx++;yy++;

    			cout << sum(xx,yy) - sum(xx,y-1) - sum(x-1,yy) + sum(x-1,y-1) << '\n';
    		}
    	}
    }

}
