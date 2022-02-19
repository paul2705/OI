#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=30;
const int MAXM=1e5+5;
int n,m,a[MAXN],b[MAXN],c[MAXN];
int x[MAXM],y[MAXM];
int pro[MAXM],cnt;
int res[MAXN],top;
bool use[MAXN];
void nexc(){
	int x=c[0];
	for (int i=0;i<m-1;i++) c[i]=c[i+1];
	c[m-1]=x;
}
void nexb(){
	int x=b[0];
	for (int i=0;i<m-1;i++) b[i]=b[i+1];
	b[m-1]=x;
}
bool sam(){
	bool f=1;
	for (int i=0;i<m;i++) f&=(c[i]==a[i]);
	return f;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) scanf("%d",&x[i]);
	for (int i=0;i<n;i++) scanf("%d",&y[i]);
	for (int i=0;i<m;i++) a[i]=i;
	n%=m*m+1;
	bool f=1;
	while (f){
		bool f1=1;
		for (int i=0;i<m;i++) f1&=(a[i]==m-i-1);
		if (f1) f=0; cnt=0;
		for (int i=0;i<m;i++) c[i]=a[i],b[i]=-1;
		for (int i=0;i<n;i++){
//			cout<<cnt<<" "<<c[0]<<" "<<c[1]<<" "<<b[0]<<" "<<b[1]<<endl;
			if (b[c[x[i]]]>=0&&b[c[x[i]]]!=y[i]) pro[cnt++]=c[x[i]];
			else b[c[x[i]]]=y[i];
//			cout<<"1: "<<cnt<<" "<<c[0]<<" "<<c[1]<<" "<<b[0]<<" "<<b[1]<<endl;
			nexc();
			if (sam()) nexb();
//			cout<<"2: "<<cnt<<" "<<c[0]<<" "<<c[1]<<" "<<b[0]<<" "<<b[1]<<endl;;
			}
		if (cnt==0){
			for (int i=0;i<m;i++) use[i]=0;
			for (int i=0;i<m;i++) if (b[i]>=0) use[b[i]]=1;
			top=0;
			while (b[top]>=0) top++;
			for (int i=0;i<m;i++){
				if (b[i]==-1) b[i]=top; top++;
				while (b[top]>=0) top++;
			}
			f=0; continue;
		}
		for (int i=0;i<cnt;i++){
			for (int j=0;j<m;j++){
				if (pro[i]==a[j]){
					pro[i]=j;
					break;
				}
			}
		}
		sort(pro,pro+cnt);
		int x=pro[0],val=a[pro[0]]; top=0;
		for (int i=x;i<m;i++) res[top++]=a[i];
		sort(res,res+top); int pos=0;
		for (int i=0;i<top;i++){
			if (res[i]==val){
				pos=i;
				break;
			}
		}
		if (pos==top-1){
			int mn=res[pos],lpos=0;
			for (int i=x-1;i>=0;i--){
				res[top++]=a[i];
				if (a[i]<mn){
					mn=a[i]; lpos=i;
					break;
				}
			}
			if (mn==res[pos]) f=0;
			sort(res,res+top); pos=0;
			for (int i=0;i<top;i++){
				if (res[i]==mn){
					pos=i;
					break;
				}
			}
			a[lpos]=res[pos+1];
			int lx=a[lpos]; lpos++;
			for (int i=0;i<top;i++){
				if (res[i]!=lx) a[lpos++]=res[i];
			}
			continue;
		}
		val=a[x]=res[pos+1]; x++;
		for (int i=0;i<top;i++){
			if (res[i]!=val) a[x++]=res[i];
		}
	}
	for (int i=0;i<m;i++) printf("%d ",a[i]); cout<<endl;
	for (int i=0;i<m;i++) printf("%d ",b[i]); cout<<endl;
	return 0;
}
