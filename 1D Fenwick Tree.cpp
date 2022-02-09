#include<bits/stdc++.h>
using namespace std;
#define int long long
class fwk{
public:
   int arr[200005];
   int fenwick[200005];
   int N;
   fwk(int n)
   {
      N = n;
      memset(fenwick,0,sizeof fenwick);
      memset(arr,0,sizeof arr);
   }

   void update(int index,int x)
   {
      for(int i=index;i<=N;i+=(i&-i))
      {
         fenwick[i]+=x;
      }
   }
   int sum(int index)
   {
      int ans = 0;
      for(int i=index;i>0;i-=(i&-i))
      {
         ans+=fenwick[i];
      }
      return ans;
   }
};

signed main()
{   
   #ifndef ONLINE_JUDGE
           freopen("input.txt","r",stdin);
           freopen("output.txt","w",stdout);
   #endif   
   ios_base::sync_with_stdio(0);cin.tie(0);cin.tie(0);
   

   int n;
   cin >> n;

   int front = 1;
   int removed[n+1];
   memset(removed,0,sizeof removed);
   fwk f(n);
   int q;
   cin >> q;
   while(q--)
   {
      int type;
      cin >> type;
      if(type == 1)
      {
         f.update(front,1);
         removed[front] = 1;
         while(removed[front] == 1)front++;

      }
      else if(type == 3)
      {
         int x;
         cin >> x;
         int s = f.sum(x);

         cout << x - s << '\n';
      }
      else
      {
         int x;
         cin >> x;
         removed[x] = 1;
         f.update(x,1);
      }
   }
   
   
}
