#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=30;
const int MAXM=1e5+5;
int a[MAXN],b[MAXN],n,m;
int x[MAXM],y[MAXM];
int res[MAXN];
bool use[MAXN];
int pro[MAXM],top=0;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&x[i]),x[i]++;
	for (int i=1;i<=n;i++) scanf("%d",&y[i]),y[i]++;
	for (int i=1;i<=m;i++) a[i]=i;
	bool f=1; int tim=0;
	while (f){
		tim++; if (tim==5) break;
		f=1;
		bool f1=1;
		for (int i=1;i<=m;i++) f1&=(a[i]==(m-i+1)),b[i]=0;
		if (f1) f=0;
		int ret=-1,cnt=0;
		top=0;
		cout<<"a: ";
		for (int i=1;i<=m;i++) cout<<a[i]<<" "; cout<<endl;
		for (int i=1;i<=m*m;i++,cnt++){
			if ((i+1)%m==0) cnt=0,ret++;
			cout<<i<<" "<<cnt<<" "<<ret<<" ";
			int ll=(x[i]-cnt+m)%m; if (ll==0) ll=m;
			cout<<ll<<" "<<((a[ll]-ret)%m+m)%m<<endl;
			if (b[((a[ll]-ret)%m+m)%m]>0){
				pro[top++]=ll;
				break;
			}
			else b[((a[ll]-ret)%m+m)%m]=y[i];
		}
		if (top==0){
			cout<<"in"<<endl;
			f=0; int rres=1;
			for (int i=1;i<=m;i++){
				if (b[i]>0) use[b[i]]=1;
			}
			while (use[rres]==1) rres++;
			for (int i=1;i<=m;i++){
				if (b[i]==0){
					b[i]=rres; rres++;
					while (use[rres]==1) rres++;
				}
			}
			break;
		}
		sort(pro,pro+top);
		cout<<"pro: "<<pro[0]<<endl;
		for (int i=pro[0];i<=m;i++) res[i-pro[0]]=a[i];
		int pos=0,x=a[pro[0]];
		sort(res,res+m-pro[0]+1); res[m-pro[0]+1]=m+1; res[0]=0;
		for (int i=0;i<=m-pro[0];i++){
			if (res[i-1]<x&&res[i+1]>x){
				pos=i;
				break;
			}
		}
		x=res[pos+1];
		if (pro[0]==m){
			cout<<"in1"<<endl;
			int mx=a[m],loc=0,top1=0;
			for (int i=m;i>0;i--){
				res[top1++]=a[i];
				if (a[i]>mx) mx=a[i];
				else{
					loc=i;
					break;
				}
			//	res[top1++]=a[i];
			}
//			cout<<res[0]<<" "<<res[1]<<" "<<top1<<endl;
			sort(res,res+top1+1);
			a[loc++]=mx;
			for (int i=0;i<=top1;i++){
				if (res[i]==mx) continue;
				a[loc++]=res[i];
			}
			continue;
		}
		int lres=pro[0]+1; a[pro[0]]=x;
		for (int i=0;i<=m-pro[0];i++){
//			cout<<res[i]<<": ";
			if (res[i]!=x) a[lres++]=res[i];
		}
//		cout<<"f: "<<f<<endl;
		if (tim==5) break;
	}
	for (int i=1;i<=m;i++) printf("%d ",a[i]-1); cout<<endl;
	for (int i=1;i<=m;i++) printf("%d ",b[i]-1); cout<<endl;
	return 0;
}
