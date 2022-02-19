#include<algorithm>
#include<cstdio>
#define mxn 1000010
#define LL long long
#define pii pair<int,int>
#define fr first
#define sc second
#define mp make_pair
using namespace std;
int n,S,sl,fh,a[mxn],lg[mxn],f[20][mxn];
int rd(){
    sl=0;fh=1;
    char ch=getchar();
    while(ch<'0'||'9'<ch) {if(ch=='-') fh=-1; ch=getchar();}
    while('0'<=ch&&ch<='9') sl=sl*10+ch-'0',ch=getchar();
    return sl*fh;
}
int qry(int l,int r){
	int res=0;
	for(int i=lg[r-l+1];~i;--i)
		if((r-l+1)>>i)
			res^=f[i][l]^((a[r]^a[l+(1<<i)-1])<<i),l+=1<<i;
	return res;
}
int main(){
	n=rd();
	for(int i=1;i<=n;++i) a[rd()]^=1;
	for(int i=2;i<=n+1;++i) lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;++i) a[i]^=a[i-1];
	for(int i=1;i<=lg[n+1];++i)
		for(int j=0;j+(1<<i)-1<=n;++j)
			f[i][j]=f[i-1][j]^f[i-1][j+(1<<(i-1))]^((a[j+(1<<i)-1]^a[j+(1<<(i-1))-1])<<(i-1));
	for(int i=1;i<=n;++i,S=0){
		for(int j=0;j<n;j+=i+1) S^=qry(j,min(n,j+i));
		if(!S) printf("Bob%c"," \n"[i==n]);
		else printf("Alice%c"," \n"[i==n]);
	}
	return 0;
}
