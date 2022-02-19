#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e2+5;
int n,a[MAXN];
int b[MAXN];
bool use[MAXN];
bool check(int mid){
	bool flag=1;
/*	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) use[j]=0,b[j]=0; use[i]=1;
		b[1]=a[i];
		for (int j=2;j<=n;j++){
			int mx=-1,pos=0;
			for (int k=1;k<=n;k++){
				if (!use[k]){
//						cout<<"in: "<<j<<" "<<k<<endl;
//						cout<<abs(a[k]-b[j-1])<<" "<<mid<<endl;
					if (abs(a[k]-b[j-1])<=mid&&abs(a[k]-b[j-1])>mx){
						mx=abs(a[k]-b[j-1]);
						pos=k;
					}
				}
			}
			if (pos==0){
				flag=0;
				break;
			}
			b[j]=a[pos]; use[pos]=1;
		}
	}
*/
	
	return flag;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int l=0,r=1e9,mid;
	while (l+1<r){
		mid=(l+r)>>1;
		if (check(mid)) r=mid;
		else l=mid;
	}
	cout<<check(l)<<" "<<l<<endl;
	check(l);
	for (int i=1;i<=n;i++) printf("%d ",b[i]);
	cout<<endl;
	return 0;
}
