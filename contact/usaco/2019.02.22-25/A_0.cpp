#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const double M=1e6;
const int MAXN=1e6+6;
double n,p[MAXN];
double mul=1,sum=0,ans=0;
int main(){
	freopen("cowdate.in","r",stdin);
	freopen("cowdate.out","w",stdout);
	scanf("%lf",&n);
	for (int i=1;i<=n;i++) scanf("%lf",&p[i]),p[i]/=M;
	for (int i=n;i>=1;i--){
		mul*=(1.0-p[i]);
		sum+=p[i]/(1.0-p[i]);
//		cout<<mul*sum<<" "<<sum<<" "<<mul<<endl;
		ans=max(ans,max(mul*sum,p[i]));
	}
	printf("%.0lf\n",ans*M);
	fclose(stdin); fclose(stdout);
	return 0;
}
