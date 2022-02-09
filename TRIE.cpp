#include<bits/stdc++.h>
#define int long long
using namespace std;




struct node
{
    char data;
    node* child[58];
    int end;
    vector<string> sug;
};

struct node* getNode(char d)
{
    struct node* a  = new node;
    a->data = d;
    a->end = 0;
    for(int i=0;i<58;i++)a->child[i]=NULL;
    return a;
}

struct node* root = getNode('/');
void T_insert(string s)
{
    
    struct node* a = root;
    for(int i=0;i<(int)s.length();i++)
    {
        char ch = tolower(s[i]);
        int index = ch-'a';

        if(!a->child[index])
        {
            a->child[index] = getNode(s[i]);
        }
        a->sug.push_back(s);
        a = a->child[index];
    }
    a->sug.push_back(s);
    a->end+=1;

}
bool T_search(string s,int n,vector<string>& ans)
{
    node* a = root;
    for(int i=0;i<(int)s.length();i++)
    {
        int index = s[i]-'a';
        if(!a->child[index])
            return false;
        a = a->child[index];
    }

    ans = a->sug;
    return true;

}

signed main()
{
    int n,m;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        string s;
        cin >> s;
        T_insert(s);
    }

    cin >> m;
    for(int i=0;i<m;i++)
    {
        string s;
        cin >> s;
        std::vector<string> ans;
        bool p = T_search(s,s.length(),ans);
        if(p)
        {
            sort(ans.begin(),ans.end());
            for(auto s:ans)cout << s << '\n';
        }
        else
        {
            cout << "No suggestions\n";
            T_insert(s);
        }
    }

}
