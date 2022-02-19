#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=55;
double p[MAXN],bin[MAXN],ans=100,c;
int n;
double mp[MAXN];
int main(){
	freopen("tvshow.in","r",stdin);
	freopen("tvshow.out","w",stdout);
	scanf("%d%lf",&n,&c);
	for (int i=1;i<=n;i++) scanf("%lf",&p[i]);
	mp[0]=bin[0]=1;
	for (int i=1;i<=n;i++){
		p[i]/=100.0;
		mp[i]=mp[i-1]*p[i];
		bin[i]=bin[i-1]*2;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=i;j++){
			if (100*bin[j-1]<=c) continue;
			double tmp=mp[j-1];
			double tmp1=1;
			for (int k=j+1;k<=i;k++) tmp1*=2*p[k];
			tmp*=(1-p[j])*(100*bin[j-1]-c)*tmp1+2*p[j]*(100*bin[j-1]-c)*tmp1;
			ans=max(ans,tmp);
		}
		ans=max(ans,mp[i]*100*bin[i]);
	}
	printf("%.9lf\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
			
