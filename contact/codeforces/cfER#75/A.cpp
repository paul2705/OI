#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
int main()
{
  ll T,j,i,cnt,n;
  cin>>T;
  for(j=1;j<=T;j++)
  {
    string s;
    map<char,ll>mp1;
 
    cin>>s;
 
    n=s.size();
    cnt=1;
    for(i=0;i<n-1;i++)
    {
      if(s[i]!=s[i+1])
      {
        if(cnt%2!=0)
        {
          mp1[s[i]]=1;
         
        }
         cnt=1;
      }
      else
        {
          cnt++;
        }
    }
 
    if(cnt%2!=0)
    {
      mp1[s[i]]=1;
    }
 
    char k;
    for(k='a';k<='z';k++)
    {
      if(mp1[k]==1)
      {
        cout<<k;
      }
    }
    cout<<endl;
 
 
  }
  return 0;
}

