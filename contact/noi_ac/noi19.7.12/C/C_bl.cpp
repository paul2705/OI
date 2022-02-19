#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int,int> par; // val, pos
const int MAXN=1e5+5;
const int MAXM=4e5+5;
int n,m,a[MAXN],b[15],cnt;
int f[MAXN],s[MAXN];
set<par> S;
void dp(){
	for (int i=0;i<=n;i++) f[i]=0;
	f[0]=1; S.clear(); S.insert(par(0,0));
	for (int i=1;i<=n;i++){
		s[i]=s[i-1]^a[i];
		for (int j=0;j<cnt;j++){
			int fd=s[i]^b[j];
			set<par>::iterator it=S.lower_bound(par(fd,0));
			if (it==S.end()) continue;
			for (;it!=S.end()&&(*it).first==fd;it++){
				f[i]|=f[(*it).second];
//				cout<<(*it).second<<" "<<i<<" "<<(s[i]^s[(*it).second])<<" "<<b[j]<<endl;
			}
		}
		S.insert(par(s[i],i));
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=m;i++){
		int op; scanf("%d",&op);
		if (op==1){
			int x,y; scanf("%d%d",&x,&y);
			a[x]=y;
		}
		else {
			scanf("%d",&cnt);
			for (int j=0;j<cnt;j++) scanf("%d",&b[j]);
//			for (int i=1;i<=n;i++) cout<<a[i]<<" ";
//			cout<<endl;
			dp();
			printf("%d\n",f[n]);
		}
	}
	return 0;
}
