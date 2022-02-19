#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int a[MAXN],b[MAXN];
int T,n,ans;
char dir[MAXN];
int main(){
	freopen("bridge.in","r",stdin);
	freopen("bridge.out","w",stdout);
	scanf("%d%d",&T,&n);
	for (int i=1;i<=n;i++){
		char c=getchar(); while (c!='W'&&c!='E') c=getchar();
		dir[i]=c; scanf("%d%d",&a[i],&b[i]);
	}
	int ret=0;
	for (int i=1;i<=n;i++){
		if (a[i]>=ret) ret=a[i];
		else {
			if (b[i]<ret-a[i]) ans++;
		}
		ret+=3;
	}
	printf("%d\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
