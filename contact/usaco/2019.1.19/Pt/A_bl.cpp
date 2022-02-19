#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=3e5+5;
int f[MAXN],n,k;
int cnt[3],a[MAXN];
int main(){
	freopen("redistricting.in","r",stdin);
	freopen("redistricting1.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		char c=getchar(); while (c!='H'&&c!='G') c=getchar();
		a[i]=(c=='H');
		f[i]=1e9;
	}
	f[1]=a[1]^1;
	for (int i=2;i<=n;i++){
		cnt[0]=cnt[1]=0;
		cnt[a[i]]++;
		for (int j=i-1;j>=max(0,i-k);j--){
//			cnt[a[j]]++;
			f[i]=min(f[i],f[j]+(cnt[1]<=cnt[0]));
			cnt[a[j]]++;
		}
//		printf("%d %d\n",i,f[i]);
	}
	printf("%d\n",f[n]);
//	fclose(stdin); fclose(stdout);
	return 0;
}
