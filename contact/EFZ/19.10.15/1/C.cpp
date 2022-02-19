#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e2+5;
int l[MAXN],r[MAXN],posl,posr;
int n,ans[MAXN],mn;
bool use[MAXN];
int main(){
	scanf("%d",&n); mn=n;
	for (int i=1;i<=n;i++) scanf("%d",&l[i]);
	for (int i=1;i<=n;i++) scanf("%d",&r[i]);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) use[j]=0;
		use[i]=1;
		posl=posr=n;
		int cnt=1;
		while (cnt<n-2){
			while (use[r[posr]]) posr--;
			use[r[posr]]=1; cnt++;
			while (use[l[posl]]) posl--;
			use[l[posl]]=1; cnt++;
//			for (int i=1;i<=n;i++) printf("%d ",use[i]);
//			printf("\n");
		}
		if (cnt==n-2){
			while (use[r[posr]]) posr--;
			use[r[posr]]=1; cnt++;
		}
		int x=-1;
		for (int j=1;j<=n;j++){
			if (!use[j]) x=j;
		}
		for (int j=1;j<=n;j++){
			if (l[j]==x){
				ans[i]=j;
				break;
			}
		}
		mn=min(mn,ans[i]);
	}
	printf("%d\n",l[mn]);
	int cnt=0;
	for (int i=1;i<=n;i++){
		if (ans[i]==mn) cnt++;
	}
	printf("%d\n",cnt);
	for (int i=1;i<=n;i++){
		if (ans[i]==mn) printf("%d ",i);
	}
	printf("\n");
	return 0;
}
