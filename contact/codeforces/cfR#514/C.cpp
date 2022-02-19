#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+6;
int n,cnt[MAXN],ret,a[10],tot,ans[MAXN][5];
int gcd(int a,int b){ return b==0?a:gcd(b,a%b); }
int main(){
	scanf("%d",&n);
	if (n==3) return printf("1 1 3\n"),0;
	else if (n==2) return printf("1 2\n"),0;
	else if (n==1) return printf("1\n"),0;
	ret=n;
	for (int i=1;i<=n&&ret>3;i+=2) cnt[i]++,ret--,printf("%d ",1);
	int x=2;
	while (ret>3){
		for (int i=x;i<=n&&ret>3;i+=x){
			if ((i%x==0)&&(i%(x*2)!=0)) cnt[i]++,ret--,printf("%d ",x);
		}
		if (ret>3) x*=2;
	}
	for (int i=1;i<=n;i++){
		if (cnt[i]==0) a[tot++]=i;
	}
	tot=0;
	for (int i=0;i<3;i++){
		for (int j=0;j<3;j++){
			for (int k=0;k<3;k++){
				if (i==j||j==k||k==i) continue;
				//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<endl;
				ans[++tot][0]=gcd(a[i],gcd(a[j],a[k]));
				ans[tot][1]=gcd(a[j],a[k]);
				ans[tot][2]=a[k];
				//cout<<x<<" "<<gcd(a[j],a[k])<<" "<<a[k]<<endl;
				sort(ans[tot],ans[tot]+3);
				//cout<<ans[tot][0]<<" "<<ans[tot][1]<<" "<<ans[tot][2]<<endl;
			}
		}
	}
//	cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
	bool f=1;
	int pos=0;
	for (int i=0;i<3&&f;i++){
		int mx=ans[1][i]; pos=1;
		for (int j=1;j<=tot;j++){
			if (ans[j][i]>mx) mx=ans[j][i],pos=j;
		}
		for (int j=1;j<=tot;j++){
			if (ans[j][i]<mx) f=0;
		}
//		cout<<i<<" "<<f<<" "<<mx<<" "<<pos<<endl;
		if (!f) break;
	}
//	cout<<pos<<endl;
	printf("%d %d %d\n",ans[pos][0],ans[pos][1],ans[pos][2]);
	return 0;
}
