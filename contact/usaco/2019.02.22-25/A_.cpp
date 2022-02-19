#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const double M=1e6;
const int MAXN=1e6+6;
double n,p[MAXN];
double mul[MAXN],sum[MAXN];
double ans=0;
double check(int l,int r){
	return mul[r]/mul[l-1]*(sum[r]-sum[l-1]);
}
int main(){
	freopen("cowdate.in","r",stdin);
	freopen("cowdate.out","w",stdout);
	scanf("%lf",&n);
	for (int i=1;i<=n;i++) scanf("%lf",&p[i]),p[i]/=M;
	mul[0]=1.0;
	for (int i=1;i<=n;i++){
		mul[i]=mul[i-1]*(1.0-p[i]);
		sum[i]=sum[i-1]+p[i]/(1-p[i]);
	}
	for (int i=1;i<=n;i++){
//		cout<<i<<endl;
		int l=i,r=n+1,ml,mr;
		while (l+1<r){
			ml=(r+l)/2;
			mr=(ml+r)/2;
//			cout<<l<<" "<<ml<<" "<<mr<<" "<<r<<endl;
			if (check(i,ml)>check(i,mr)) r=mr;
			else l=ml;
		}
		ans=max(ans,max(check(i,l),check(i,r)));
	}
	printf("%.0lf\n",ans*M);
	fclose(stdin); fclose(stdout);
	return 0;
}
