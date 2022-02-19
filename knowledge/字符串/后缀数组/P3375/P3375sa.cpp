#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=3e6+6;
int n,m;
int sa[MAXN],rk[MAXN],x[MAXN];
int cnt[MAXN],h[MAXN];
int nxt[MAXN],ans[MAXN];
char a[MAXN],b[MAXN];
int la,lb;
int main(){
	scanf("%s",b+1);
	lb=strlen(b+1);
	scanf("%s",a+1);
	la=strlen(a+1);
	n=strlen(a+1);
	for (int i=1;i<=la;i++) m=max(m,(int)a[i]);
	for (int i=1;i<=lb;i++) m=max(m,(int)b[i]);
//	cout<<a+1<<" "<<n<<endl;
	int mx=m+5;
	for (int i=1;i<=n;i++) cnt[rk[i]=a[i]]++;
	for (int i=1;i<=mx;i++) cnt[i]+=cnt[i-1];
	for (int i=n;i>=1;i--) sa[cnt[rk[i]]--]=i;
	for (int k=1;k<=n;k<<=1){
		int tmp=1;
		for (int i=n-k+1;i<=n;i++) x[tmp++]=i;
		for (int i=1;i<=n;i++){
			if (sa[i]>k) x[tmp++]=sa[i]-k;
		}
		for (int i=1;i<=mx;i++) cnt[i]=0;
		for (int i=1;i<=n;i++) cnt[rk[x[i]]]++;
		for (int i=1;i<=mx;i++) cnt[i]+=cnt[i-1];
		for (int i=n;i>=1;i--) sa[cnt[rk[x[i]]]--]=x[i];
		for (int i=1;i<=n;i++) swap(rk[i],x[i]);
		tmp=1; rk[sa[1]]=1;
		for (int i=2;i<=n;i++){
			if (!(x[sa[i]]==x[sa[i-1]]&&x[sa[i]+k]==x[sa[i-1]+k])) tmp++;
			rk[sa[i]]=tmp;
		}
		if (tmp==n) break;
		mx=tmp+1;
	}
	for (int i=1;i<=n;i++) rk[sa[i]]=i;
	int stp=0;
	for (int i=1;i<=n;i++){
		int pre=sa[rk[i]-1];
		if (stp) stp--;
		while (a[pre+stp]==a[i+stp]&&max(i,pre)+stp<=n) stp++;
		h[rk[i]]=stp;
	}
//	for (int i=1;i<=n;i++) cout<<sa[i]<<" "<<h[i]<<endl;
	int pos=rk[1];
	int mn=1e9;
	nxt[1]=0;
	for (int i=pos-1;i>=1;i--){
		mn=min(mn,h[i+1]);
		int t=mn;
		while (t>0){ nxt[sa[i]+t-1]=max(nxt[sa[i]+t-1],t);t--; }
	}
	mn=1e9;
	for (int i=pos+1;i<=n;i++){
		mn=min(mn,h[i]);
		int t=mn;
		while (t>0){ nxt[sa[i]+t-1]=max(nxt[sa[i]+t-1],t);t--; }
	}
	a[la+1]='$';
	for (int i=1;i<=lb;i++) a[i+la+1]=b[i];
	n=strlen(a+1);
//	cout<<a+1<<" "<<n<<endl;
	for (int i=1;i<=3e6+4;i++) cnt[i]=rk[i]=sa[i]=x[i]=h[i]=0;
	for (int i=1;i<=n;i++) cnt[rk[i]=a[i]]++;
	mx=m+5;
	for (int i=1;i<=mx;i++) cnt[i]+=cnt[i-1];
	for (int i=n;i>=1;i--) sa[cnt[rk[i]]--]=i;
//	for (int i=1;i<=n;i++) cout<<sa[i]<<" ";
//	cout<<endl;
	for (int k=1;k<=n;k<<=1){
		int tmp=1;
		for (int i=n-k+1;i<=n;i++) x[tmp++]=i;
		for (int i=1;i<=n;i++){
			if (sa[i]>k) x[tmp++]=sa[i]-k;
		}
		for (int i=1;i<=mx;i++) cnt[i]=0;
		for (int i=1;i<=n;i++) cnt[rk[x[i]]]++;
		for (int i=1;i<=mx;i++) cnt[i]+=cnt[i-1];
		for (int i=n;i>=1;i--) sa[cnt[rk[x[i]]]--]=x[i];
		for (int i=1;i<=n;i++) swap(rk[i],x[i]);
		tmp=1; rk[sa[1]]=1;
		for (int i=2;i<=n;i++){
			if (!(x[sa[i]]==x[sa[i-1]]&&x[sa[i]+k]==x[sa[i-1]+k])) tmp++;
			rk[sa[i]]=tmp;
		}
//		for (int i=1;i<=n;i++) cout<<sa[i]<<" ";
//		cout<<endl;
		if (tmp==n) break;
		mx=tmp+1;
	}
	for (int i=1;i<=n;i++) rk[sa[i]]=i;
	stp=0;
	for (int i=1;i<=n;i++){
		int pre=sa[rk[i]-1];
		if (stp) stp--;
		while (a[pre+stp]==a[i+stp]&&max(pre,i)+stp<=n) stp++;
		h[rk[i]]=stp;
	}
//	for (int i=1;i<=n;i++) cout<<i<<" "<<sa[i]<<" "<<h[i]<<endl;
	pos=rk[1];
	mn=1e9;
	int tmp=0;
	for (int i=pos-1;i>=1;i--){
		mn=min(mn,h[i+1]);
		if (sa[i]>la+1&&mn>=la) ans[tmp++]=sa[i];
	}
	mn=1e9;
	for (int i=pos+1;i<=n;i++){
		mn=min(mn,h[i]);
		if (sa[i]>la+1&&mn>=la) ans[tmp++]=sa[i];
	}
	sort(ans,ans+tmp);
	for (int i=0;i<tmp;i++) printf("%d\n",ans[i]-la-1);
	for (int i=1;i<=la;i++) printf("%d ",nxt[i]);
	return 0;
}
