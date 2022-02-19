#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
using namespace std;
char s[500005];
map <pair<int,int>,int> mp;
map <pair<pair<int,int>,pair<int,int> >,int> mp2;
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	int x=0,y=0,ans=1;
	mp[make_pair(x,y)]=1;
	for(int i=1;i<=n;i++){
		if(s[i]=='U') ans-=mp2[make_pair(make_pair(x,y),make_pair(x,y+1))],
		mp2[make_pair(make_pair(x,y),make_pair(x,y+1))]
		=mp2[make_pair(make_pair(x,y+1),make_pair(x,y))]=1,++y;
		if(s[i]=='D') ans-=mp2[make_pair(make_pair(x,y),make_pair(x,y-1))],
		mp2[make_pair(make_pair(x,y),make_pair(x,y-1))]
		=mp2[make_pair(make_pair(x,y-1),make_pair(x,y))]=1,--y;
		if(s[i]=='L') ans-=mp2[make_pair(make_pair(x-1,y),make_pair(x,y))],
		mp2[make_pair(make_pair(x,y),make_pair(x-1,y))]
		=mp2[make_pair(make_pair(x-1,y),make_pair(x,y))]=1,--x;
		if(s[i]=='R') ans-=mp2[make_pair(make_pair(x+1,y),make_pair(x,y))],
		mp2[make_pair(make_pair(x,y),make_pair(x+1,y))]
		=mp2[make_pair(make_pair(x+1,y),make_pair(x,y))]=1,++x;
		if(mp[make_pair(x,y)]) ++ans;
		mp[make_pair(x,y)]=1;
	}
	cout<<ans<<endl;
	return 0;
}
