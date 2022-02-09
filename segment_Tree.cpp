#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 100000000000;
const int N = 2000005;
int a[N];
int st[4*N];
int lazy[4*N];
void build(int index,int start,int end)
{
	if(start == end)
	{
		st[index] = a[start];
		return;
	}

	int mid = (start+end)/2;

	build(2*index,start,mid);
	build(2*index+1,mid+1,end);

	st[index] = st[2*index] + st[2*index+1]; 
}
int query(int index,int start,int end,int qs,int qe)
{
	if(lazy[index]!=0)
	{
		int dx = lazy[index];
		st[index] += dx*(end-start+1);
		lazy[index] = 0;
		if(start!=end)
		{
			lazy[2*index]+=dx;
			lazy[2*index+1]+=dx;
		}
	}
	if(qs > end || qe < start)
		return 0;
	if(start>=qs && end<=qe)
		return st[index];

	int mid = (start+end)/2;
	int l = query(2*index,start,mid,qs,qe);
	int r = query(2*index+1,mid+1,end,qs,qe);

	return l+r;
}
void update(int index,int start,int end,int q)
{
	if(start == end)
	{
		st[index] = a[start];
		return;
	}
	int mid = (start+end)/2;
	if(q<=mid)
		update(2*index,start,mid,q);
	else
		update(2*index+1,mid+1,end,q);
	st[index] = st[2*index] + st[2*index+1];
}

void lazy_update(int index,int start,int end,int us,int ue,int val)
{
	if(lazy[index]!=0)
	{
		int dx = lazy[index];
		st[index] += dx*(end-start+1);
		lazy[index] = 0;
		if(start!=end)
		{
			lazy[2*index]+=dx;
			lazy[2*index+1]+=dx;
		}
	}

	if(start>ue || end<us)
		return;

	if(us>=start && ue<=end)
	{
		st[index]+=val*(end-start+1);

		if(start!=end){
			lazy[2*index]+=val;
			lazy[2*index+1]+=val;
		}
		return;
	}
	int mid = (start+end)/2;

	lazy_update(2*index,start,mid,us,ue,val);
	lazy_update(2*index+1,start,end,us,ue,val);

	st[index] = st[2*index] + st[2*index+1];
}


signed main()
{	
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
	#endif	

    cout << "Ho";
}




