#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int a[200010];
long long sum[200010];
bool cmp(int x,int y){
	return x>y;
}
long long gcd(long long a,long long b){
	return b==0?a:gcd(b,a%b);
}
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++)
			sum[i]=sum[i-1]+a[i];
		long long x,a,y,b,k,ans=0;
		cin>>x>>a>>y>>b>>k;
		bool flag=false;
		long long lcm=a*b/gcd(a,b);
		for(int i=1;i<=n;i++){
			long long cnt=i/lcm;
			long long numa=i/a-cnt;
			long long numb=i/b-cnt;
			long long ans1=((x+y)*sum[cnt]/100)+(x*(sum[cnt+numa]-sum[cnt])/100)+((y*(sum[cnt+numa+numb]-sum[cnt+numa]))/100);
			long long ans2=((x+y)*sum[cnt]/100)+(y*(sum[cnt+numb]-sum[cnt])/100)+((x*(sum[cnt+numa+numb]-sum[cnt+numb]))/100);
			long long maxn=max(ans1,ans2);
			if(maxn>=k){
				flag=true;
				ans=i;
				break;
			}
		}
		if(flag)
			cout<<ans<<endl;
		else
			cout<<"-1"<<endl;
	}
	return 0;
}
