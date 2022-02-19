#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e3+5;
int a[MAXN][MAXN];
int n,m;
int pre[MAXN],nxt[MAXN];
int ans=0;
bitset<2005> res,tmp,t;
int main(){
	freopen("window.in","r",stdin);
	freopen("window.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) scanf("%d",&a[i][j]);
	}
	for (int i=2;i<=n;i++){
		int head=1;
		for (int i=1;i<=n-1;i++) nxt[i]=i+1,pre[i]=i-1;
		res=(1<<(n-1))-1;
		for (int j=i;j<n;j++){
			for (int now=head;now!=n;now=nxt[now]){
//				cout<<"cnt: "<<now-1<<","<<j<<" "<<now<<","<<j<<endl;
				if (a[now][j]==a[now+1][j]){
//					cout<<now<<endl;
					res^=(1<<(now-1));
					nxt[pre[now]]=nxt[now];
					pre[nxt[now]]=pre[now];
				}
			}
//			cout<<i<<" "<<j<<" "<<res<<endl;
			int l=1;
			for (int r=l;l<=n-1;l=r+1,r++){
				while (l<=n-1&&a[l][j]==a[l][j+1]) l++;
				int cnt=1;
				t.reset();
				t[0]=1;
				r=l;
				while (r<=n-1&&a[r+1][j]!=a[r+1][j+1]) r++,t[cnt++]=1;
				if (r-l+1<j-i+1) continue;
//				cout<<l<<" "<<r<<" "<<t<<endl;
				tmp=(res>>(l-1))&t;
				tmp=tmp&(tmp>>(j-i+1));
				if (tmp.count()) ans=max(ans,j-i+1);
			}
//			cout<<"ans: "<<ans<<endl;
		}
	}
	printf("%d\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
