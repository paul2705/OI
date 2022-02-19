#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf=1e9;
const int MAXN=2e3+5;
char s[MAXN];
int n;
int a[MAXN],b[MAXN];
int f[MAXN],cnt[MAXN];
int pre1[MAXN],pre2[MAXN];
int div(){
	int k=0;
	if (b[0]==1&&b[1]<4){
		b[0]=0;
		k=b[1];
		b[1]=0;
		return k;
	}
	for (int i=b[0];i>=1;i--){
		if ((k*10+b[i])<4){
			k=k*10+b[i];
			b[i]=0;
			continue;
		}
		else {
			int tmp=b[i];
			b[i]=(k*10+tmp)/4;
			k=(k*10+tmp)%4;
		}
	}
	while (b[b[0]]==0) b[0]--;
//	cout<<__func__<<endl;
//	for (int i=b[0];i>=1;i--) printf("%d",b[i]);
//	cout<<endl;
	return k;
}
int main(){
	scanf("%s",s+1);
	int len=strlen(s+1);
	for (int i=1;i<=len;i++) b[i]=s[len-i+1]-'0';
	b[0]=len;
	while (b[0]) a[++n]=div();
//	for (int l=1,r=n;l<r;l++,r--) swap(a[l],a[r]);
	for (int i=1;i<=n;i++) printf("%d",a[i]);
	cout<<endl;
	for (int i=1;i<=n;i++) f[i]=inf,a[i]+=a[i-1];
	f[0]=0; cnt[0]=1;
	for (int i=1;i<=n;i++){
		for (int j=0;j<i;j++){
			if (f[i]>=f[j]+a[i]-a[j]){
				f[i]=f[j]+a[i]-a[j];
				pre1[i]=j;
			}
			if (f[i]>=f[j]+3*i-a[i]+a[j]+2){
				f[i]=f[j]+3*i-a[i]+a[j]+2;
				pre2[i]=j;
			}
		}
		cout<<i<<" "<<f[i]<<endl;
	}
	pre1[0]=pre2[0]=n+1;
	cnt[n+1]=0;
	for (int i=1;i<=n;i++){
		for (int j=0;j<i;j++){
			if (f[j]+a[i]-a[j]==f[i]) cnt[i]+=cnt[j]-cnt[pre1[j]];
			if (f[j]+3*i-a[i]+a[j]+2==f[i]) cnt[i]+=cnt[j]-cnt[pre2[j]];
//			if (cnt[i]>0) break;
		}
		cout<<i<<" "<<cnt[i]<<endl;
	}
	printf("%d\n",cnt[n]);
	return 0;
}
