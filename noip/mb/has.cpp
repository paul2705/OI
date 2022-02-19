#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
const int MAXN=1e4+5;
map<string,bool> mp;
string s;
int n;
int main(){
	scanf("%d",&n);
	int ans=n;
	for (int i=1;i<=n;i++){
		cin>>s;
		if (mp[s]) ans--;
		mp[s]=1;
	}
	printf("%d\n",ans);
	return 0;
}
