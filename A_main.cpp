class Solution {
public:
    int minCharacters(string a, string b) {

        int dp[n+1][26];
        int dp2[n+1][26];

        for(int i=1;i<=a.length();i++)
        {
            for(int j=0;j<26;j++)dp[i][j] = dp[i-1][j];
            dp[i][a[i-1]-'a']++;
        }

        for(int i=1;i<=b.length();i++)
        {
            for(int j=0;j<26;j++)dp2[i][j] = dp2[i-1][j];
            dp2[i][b[i-1]-'a']++;
        }


        int conversion_a[26];
        int conversion_b[26];


        for(int i=0;i<26;i++)
        {
            conversion_a[i] = a.length() - dp[n][i];
        }

        for(int i=0;i<26;i++)
        {
            conversion_b[i] = b.length() - dp2[n][i];
        }

        int mx = 1000000000;

        for(int i=0;i<26;i++)
        {
            mx = min(mx,conversion_a[i] + conversion_b[i]);
        }

        for(int i=0;i<26;i++)
        {
            for(int j=i+1;j<26;j++)
            {
                int x = i;
                int y = j;
                int xsum = 0;
                for(int k=0;k<x;k++)xsum+=dp[n][k];
                int ysum = 0;
                for(int k=j;k<26;k++)ysum+=dp2[m][k];
                mx = min(mx,xsum+ysum);

                swap(x,y);
                xsum = 0;
                ysum = 0;
                for(int k=0;k<x;k++)xsum+=dp[n][k];
                int ysum = 0;
                for(int k=j;k<26;k++)ysum+=dp2[m][k];
                mx = min(mx,xsum+ysum);

            }
        }

        return mx;

        
    }
};