#include<bits/stdc++.h>
#define FIO "count"
#define INF 0x3f3f3f
#define DBUG(...) fprintf(stderr,__VA_ARGS__)
typedef long long ll;
const int MOD=1e9+7,MAXN=1e5;
using namespace std;
char buf[1<<20];int bufl,bufr;
#define getch ((bufl^bufr||(bufl=0,bufr=fread(buf,1,1<<20,stdin)))?buf[bufl++]:EOF)
template <class T>inline void read(T &x){T f=1;x=0;char ch=getchar();for(;!isdigit(ch)&&ch!='-';ch=getchar());if(ch=='-')f=-1,ch=getchar();for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';x*=f;}
int N,M,a[5][5],t[25],ans,P,flag;
inline int check(int x,int y){
	for(int i=1;i<=N;i++)if(a[i][y]>a[x][y])return 0;
	for(int i=1;i<=M;i++)if(a[x][i]>a[x][y])return 0;
	return 1;
}
int main(){
	freopen(FIO".in","r",stdin);
	freopen(FIO".out","w",stdout);
	read(N);read(M);read(P);
	for(int i=1;i<=N*M;i++)t[i]=i;
	do{
		flag=0;
		for (int i=1;i<=N;i++)
			for (int j=1;j<=M;j++)
				a[i][j]=t[(i-1)*M+j];
		for(int i=1;i<=N&&flag<=1;i++)
			for(int j=1;j<=M&&flag<=1;j++)if(check(i,j))	flag++;
		ans=(ans+(flag==1))%P;
	}while (next_permutation(t+1,t+N*M+1));
	printf("%d\n",ans);
	return 0;
}
