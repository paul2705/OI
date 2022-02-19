#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e5+5;
int a[MAXN],tmp[MAXN];
int n,m;
int main(){
	freopen("1.in","r",stdin);
	freopen("1.ans","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=m;i++){
		int l,r; scanf("%d%d",&l,&r);
		int cnt=0;
		for (int j=l;j<=r;j++) tmp[cnt++]=a[j];
		sort(tmp,tmp+cnt);
		int cntd=0,cnt0=0;
		for (int l=0,r=0;l<cnt;l=r+1,r++){
			while (r+1<cnt&&tmp[l]==tmp[r+1]) r++;
//			cout<<": "<<l<<" "<<r<<endl;
			if (tmp[l]==0){ cnt0=r-l+1; continue; }
			if ((r-l+1)%2==1) cntd++;
		}
		int rest=r-l+1-cntd-cnt0;
//		cout<<cnt0<<" "<<rest<<" "<<cntd<<endl;
		printf("%d\n",rest/2+((cntd+1)/2)*2);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
