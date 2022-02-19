#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=3e5+5;
int n,m,a[MAXN],b[MAXN];
int p[MAXN],pos;
int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		char c=getchar(); while (c!='0'&&c!='1') c=getchar();
		a[i]=c-'0';
	}
	for (int i=1;i<=m;i++){
		char c=getchar(); while (c!='0'&&c!='1') c=getchar();
		b[i]=c-'0';
	}
	pos=1;
	for (int i=1;i<=n;i++){
		if (pos<=m&&a[i]==b[pos]) p[pos++]=i;
	}
//	for (int i=1;i<=m;i++) printf("%d ",p[i]);
//	cout<<endl;
	bool fl=0;
	pos--;
	for (int i=n;i>=1;i--){
		while (pos&&p[pos]>i) pos--;
		if (a[i]!=a[i-1]){
			if (p[pos]==i||p[pos]==i-1) continue;
			if (pos<=0) fl=1;
//			cout<<i<<" "<<pos<<" "<<p[pos]<<"->";
			if (b[pos]==a[i]) p[pos]=i;
			else p[pos]=i-1;
//			cout<<p[pos]<<endl;
		}
	}
	if (fl) return printf("-1\n"),0;
	for (int i=1;i<=m;i++) printf("%d ",p[i]);
	cout<<endl;
	fclose(stdin); fclose(stdout);
	return 0;
}
