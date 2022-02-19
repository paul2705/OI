#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=6e3+5;
int n,m,a[MAXN];
int main(){
	freopen("C.in","r",stdin);
	freopen("C.ans","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		 scanf("%d",&a[i]);
	}
	for (int i=1;i<=m;i++){
		int op,x; scanf("%d",&op);
		if (op==1) scanf("%d",&x),a[++n]=x;
		if (op==2){
			scanf("%d",&x);
			for (int i=1;i<=n;i++){
				if (a[i]==x){
					swap(a[i],a[n]);
					break;
				}
			}
			if (a[n]==x) n--;
		}
		if (op==3){
			for (int i=1;i<=n;i++) a[i]++;
		}
		if (op==4){
			scanf("%d",&x);
			for (int i=1;i<=n;i++) a[i]^=x;
		}
	}	
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) printf("%d\n",a[i]);
	fclose(stdin); fclose(stdout);
	return 0;
}
