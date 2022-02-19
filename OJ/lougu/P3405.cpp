#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
const int MAXN=2e5+5;
map<int,int> mp[MAXN];
int n,ans;
string a,b;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		cin>>a>>b;
		int x=a[0]*26+a[1],y=b[0]*26+b[1];
		ans+=mp[y][x];
		if (x==y) ans-=mp[y][x];
		mp[x][y]++;
	}
	printf("%d\n",ans);
	return 0;
}
