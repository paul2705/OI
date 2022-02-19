#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e5+5;
int a[MAXN],n,m;
bool use[MAXN];
int ans;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		char c=getchar(); while (c!='1'&&c!='0') c=getchar();
		a[i]=c-'0'; if (a[i]==0) a[i]=-1;
	}
	for (int i=1,l,r;i<=m;i++){
		scanf("%d%d",&l,&r);
		for (int i=l;i<=r;i++) use[i]=0;
		int s=0;
		for (int i=l;i<=r;i++){
//			cout<<"a: "<<a[i]<<": ";		
			s+=a[i];
			if (s>0) ans++,s=0,use[i]=1;
		}
		s=0;
		for (int i=r;i>=l;i--){
			if (!use[i]){
				s+=a[i];
				if (s>0) ans++,s=0,use[i]=1;
			}
		}
//		cout<<endl;
		printf("%d\n",ans);
		ans=0;
	}
	return 0;
}
