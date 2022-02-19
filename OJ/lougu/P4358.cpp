#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+6;
int n,pc,ans;
bool vis[MAXN];
int p[MAXN],phi[MAXN];
int main(){
	scanf("%d",&n);
	for (int x=2;x<=n+1;x++){
		if (!vis[x]) p[++pc]=x,phi[x]=x-1;
		if (n%(x-1)==0) ans+=phi[x];
		for (int i=1;x*p[i]<=n+1;i++){
			vis[x*p[i]]=1;
			if (x%p[i]==0){ phi[x*p[i]]=phi[x]*p[i]; break; }
			else phi[x*p[i]]=phi[x]*phi[p[i]];
		}
	}
	printf("%d\n",(ans+1)/2);
	return 0;
}
