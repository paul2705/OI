#include<cstdio>
#include<vector>
using namespace std;
int n,m,p,q;
char s[1000010];
vector<int> a[1000010],b[1000010];
long long x1,y1,x2,y2,li,ri,lj,rj,r1,r2,r3,r4,ans;
void read(int &n,int &m,vector<int> a[]){
	scanf("%d%d%s",&n,&m,s);
	for(int i=1;i<=n;i++) a[i].push_back(0);
	for(int i=0;i<=m;i++) a[0].push_back(0);
	for(int i=1,t=0;i<=n;i++)
		for(int j=1;j<=m;j++) a[i].push_back(s[t++]-48);
}
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int calc(int x1,int y1,int x2,int y2,int x){
	int _=b[x2][y2]-b[x1-1][y2]-b[x2][y1-1]+b[x1-1][y1-1];
	return x?_:(x2-x1+1)*(y2-y1+1)-_;
}
int main(){
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
	read(n,m,a),read(p,q,b);
	for(int i=1;i<=p;i++)
		for(int j=1;j<=q;j++)
		b[i][j]+=b[i][j-1]+b[i-1][j]-b[i-1][j-1];
	x1=p/gcd(n,p),y1=q/gcd(m,q),x2=n/gcd(n,p),y2=m/gcd(m,q);
	for(int i=1,x;i<=n;i++)
		for(int j=1;j<=m;j++){
			li=(x1*i-x1+x2)/x2,ri=(x1*i-1)/x2+1;
			lj=(y1*j-y1+y2)/y2,rj=(y1*j-1)/y2+1;
			r1=x2*li-x1*i+x1,r2=x1*i-x2*ri+x2;
			r3=y2*lj-y1*j+y1,r4=y1*j-y2*rj+y2,x=a[i][j];
			ans+=r1*r3*calc(li,lj,li,lj,x);
			ans+=r1*y2*calc(li,lj+1,li,rj-1,x);
			ans+=r1*r4*calc(li,rj,li,rj,x);
			ans+=x2*r3*calc(li+1,lj,ri-1,lj,x);
			ans+=x2*y2*calc(li+1,lj+1,ri-1,rj-1,x);
			ans+=x2*r4*calc(li+1,rj,ri-1,rj,x);
			ans+=r2*r3*calc(ri,lj,ri,lj,x);
			ans+=r2*y2*calc(ri,lj+1,ri,rj-1,x);
			ans+=r2*r4*calc(ri,rj,ri,rj,x);
		}
	printf("%lld",ans);
	return 0;
}
