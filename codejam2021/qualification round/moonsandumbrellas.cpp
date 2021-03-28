/*
 Input:
 4
2 3 CJ?CC?
4 2 CJCJ
1 3 C?J
2 5 ??J???

Output:
Case #1: 5
Case #2: 10
Case #3: 1
Case #4: 0

 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
    int n,X,Y,cnt=0,ans=0;
    string s;
    cin>>X>>Y>>s;
    int i,j;
    n=s.length();
    for(i=0;i<n;i++)
    {
        if(s[i]=='?')
            cnt++;
    }
    if(cnt==n || cnt==n-1)
    {
        cout<<"0";
        return;
    }
    int k;
    for(k=0;k<n-1;k++)
    {
        if(s[k]!='?')
            break;
    }
    if(k==0)
        k++;
    i=k;
    while(i<n-1)
    {
        if(s[i]=='?')
        {
            if(s[i-1]!=s[i+1] && s[i+1]!='?')
            {
                if(s[i-1]=='J')
                    ans+=Y;
                else
                    ans+=X;
            }
            else if(s[i-1]!=s[i+1] && s[i+1]=='?')
            {
                j=i+2;
                while(s[j]=='?' && j<n)
                {
                    j++;
                }
                if(j==n)
                {
                    break;
                }
                if(s[i-1]!=s[j])
                {
                    if(s[i-1]=='J')
                        ans+=Y;
                    else
                        ans+=X;
                }
                i=j;
            }
        }
        i++;
    }
    for(i=0;i<n-1;i++)
    {
        if(s[i]=='J' && s[i+1]=='C')
            ans+=Y;
        else if(s[i]=='C' && s[i+1]=='J')
            ans+=X;
    }
    cout<<ans;


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll T;
    cin>>T;
    for(int j=1;j<=T; j++)
    {
        cout<<"Case #"<<j<<": ";
        solve();
        cout<<endl;
    }
}
