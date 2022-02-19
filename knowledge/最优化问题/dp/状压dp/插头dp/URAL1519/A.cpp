#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<bitset>
using namespace std;
typedef long long ll;
const int MAXN=15;
map<int,ll> f[MAXN][MAXN];
map<int,bool> bk[MAXN][MAXN];
int n,m;
int edx,edy;
char a[MAXN][MAXN];
bitset<10> lok;
int get(int s,int x){
	int fir=0,sec=0;
	if (s&(1<<(2*x))) sec=1;
	if (s&(1<<(2*x+1))) fir=1;
	return fir*2+sec;
}
void chg(int &s,int x,int y){
	int fir=y/2,sec=y%2;
	lok=s; cout<<lok<<" "<<x<<" "<<y<<" "<<fir<<" "<<sec<<" ";
	s&=(((1<<(2*x))-1)&((1<<(2*x+1))-1));
	s|=((1<<(2*x)*sec)|(1<<(2*x+1)*fir));
	lok=s; cout<<lok<<endl;
}
ll dp(int x,int y,int s){
	if (y==m+1){
		s<<=2;
		return f[x][y][s]=dp(x+1,1,s);
	}
	else {
		int l=get(s,y-1),r=get(s,y);
		int ns=s;
		if (bk[x][y][s]) return f[x][y][s];
		bk[x][y][s]=1;
		if (a[x][y]=='#'){
			if (l==0&&r==0) return f[x][y][s]=dp(x,y+1,ns);
			else return f[x][y][s]=0;
		}
		if (l==r){
			if (l==0){
				chg(ns,y-1,1); chg(ns,y,2);
				return f[x][y][s]=dp(x,y+1,ns);
			}
			if (l==1){
				for (int i=y+1;i<=n;i++){
					int now=get(s,i);
					if (now==2){
						chg(ns,i,1);
						break;
					}
				}
				chg(ns,y-1,0); chg(ns,y,0);
				return f[x][y][s]=dp(x,y+1,ns);
			}
			if (l==2){
				for (int i=0;i<y-1;i++){
					int now=get(s,i);
					if (now==2){
						chg(ns,i,1);
						break;
					}
				}
				chg(ns,y-1,0); chg(ns,y,0);
				return f[x][y][s]=dp(x,y+1,ns);
			}
		}
		if (l==0||r==0){
			f[x][y][s]=dp(x,y+1,ns);
			chg(ns,y-1,1); chg(ns,y,2);
			return f[x][y][s]=f[x][y][s]+dp(x,y+1,ns);
		}
		if (l!=r){
			chg(ns,y-1,0); chg(ns,y,0);
			if (x==edx&&y==edy) return f[x][y][s]=1;
			else return f[x][y][s]=dp(x,y+1,ns);
		}
	}
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			char c=getchar(); while (c!='.'&&c!='*') c=getchar();
			a[i][j]=c;
		}
	}
	for (int i=n;i>=1;i--){
		bool flag=0;
		for (int j=1;j<=m;j++)
			if (a[i][j]=='.') flag=1;
		if (!flag) n--;
	}
	for (int i=m;i>=1;i--){
		if (a[n][i]=='.'){
			edx=n; edy=i;
			break;
		}
	}
	f[1][1][0]=dp(1,1,0);
	printf("%lld\n",f[1][1][0]);
	return 0;
}
