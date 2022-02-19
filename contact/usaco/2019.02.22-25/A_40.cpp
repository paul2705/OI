#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const double M=1e6;
const int MAXN=1e6+5;
double n,p[MAXN],sum[MAXN],mul[MAXN];
double ans=0;
int main(){
	freopen("cowdate.in","r",stdin);
	freopen("cowdate.out","w",stdout);
	scanf("%lf",&n);
	for (int i=1;i<=n;i++) scanf("%lf",&p[i]);
//	mul[0]=1.0;
//	for (int i=1;i<=n;i++){
//		cout<<p[i]<<endl;
//		mul[i]=mul[i-1]*(1.0-p[i]);
//		sum[i]=sum[i-1]+p[i]/(1.0-p[i]);
//	}
	for (int i=1;i<=n;i++){
		double lans=0,mul=M;
		for (int j=i;j<=n;j++){
			double res=lans*(M-p[j])/M+mul*p[j]/M;
//			cout<<i<<" "<<j<<" "<<res<<endl;
			ans=max(ans,res);
			mul*=(M-p[j])/M;
//			if (res<lans) printf("wrong\n");
			lans=res;
		}
	}
//	printf("Yes\n");
	printf("%.0lf\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
