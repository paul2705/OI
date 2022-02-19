#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
#include<vector>
using namespace std;
const int MAXN=1e5+50;
bitset<5000> st[MAXN];
int n,m,a[20][MAXN];
int q,cnt;
bool check(int x,int y,int mid){
	int tmp=0;
//	cout<<__func__<<endl;
//	cout<<x<<" "<<mid<<endl;
//	cout<<res[y][mid]<<endl;
	for (int i=m;i>=0;i--){
		if (a[i][y]>=mid) tmp=tmp<<1|1;
		else tmp<<=1;
	}
	return st[x][tmp];
}
int main(){
	freopen("first.in","r",stdin);
	freopen("first.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for (int i=0;i<m;i++){
		for (int j=1;j<=n;j++) scanf("%d",&a[i][j]);
		for (int s=0;s<(1<<m);s++){
			st[i][s]=(s>>i)&1;
		}
	}
//	cout<<"done"<<endl;
	cnt=m-1;
	for (int i=1;i<=q;i++){
		int op,x,y; scanf("%d%d%d",&op,&x,&y);
		x--;
		if (op==1) st[++cnt]=st[x]|st[y-1];
		if (op==2) st[++cnt]=st[x]&st[y-1];
		if (op==3){
			int l=0,r=1e9+1,mid;
			while (l+1<r){
//				cout<<l<<" "<<r<<" "<<endl;
				mid=(l+r)>>1;
				if (check(x,y,mid)) l=mid;
				else r=mid;
			}
//			cout<<check(x,y,0)<<" "<<check(x,y,1)<<" "<<check(x,y,2)<<endl;
//			cout<<"f**"<<" "<<l<<endl;
			printf("%d\n",l);
		}
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
