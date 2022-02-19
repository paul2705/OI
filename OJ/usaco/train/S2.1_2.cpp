/*
ID: paul1202
LANG: C++
TASK: frac1
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=165;
bool a[MAXN][MAXN];
int n,cnt;
struct rec{
	int x,y;
} lis[MAXN*MAXN];
bool cmp(rec a,rec b){ return a.x*b.y<b.x*a.y; }
int gcd(int a,int b){ return b==0?a:gcd(b,a%b); }
int main(){
	freopen("frac1.in","r",stdin);
	freopen("frac1.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (i>j) continue;
			int d=gcd(i,j);
			int x=i/d,y=j/d;
			a[x][y]=1;
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (a[i][j]) lis[cnt++]=(rec){i,j};
		}
	}
	sort(lis,lis+cnt,cmp);
	cout<<"0/1"<<endl;
	for (int i=0;i<cnt;i++){
		printf("%d/%d\n",lis[i].x,lis[i].y);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
