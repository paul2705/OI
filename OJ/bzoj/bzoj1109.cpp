#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int n,f[MAXN];
struct rec{
	int x,y;
} a[MAXN];
int len=0;
int find(int x){
	int l=0,r=len+1,mid;
	while (l+1<r){
		mid=(l+r)>>1;
		if (f[mid]>=x) r=mid;
		else l=mid;
	}
	return l;
}
bool cmp(rec a,rec b){ return a.x==b.x?a.y<b.y:a.x>b.x; }
int main(){
	freopen("bzoj1109.in","r",stdin);
	freopen("bzoj1109.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i].y),a[i].x=a[i].y-i;
//	f[++len]=a[1];
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++){
		if (a[i].x>0) continue;
		int pos=find(a[i].y);
//		cout<<i<<" "<<a[i]<<" "<<pos<<endl;
		len=max(len,pos+1);
		f[pos+1]=a[i].y;
	}
	printf("%d\n",len);
	fclose(stdin); fclose(stdout);
	return 0;
}
