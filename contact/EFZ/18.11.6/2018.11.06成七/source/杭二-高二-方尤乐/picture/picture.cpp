#include <bits/stdc++.h>
using namespace std;
#define ref(i,x,y)for(int i=x;i<=y;++i)
typedef long long LL;
const int N=1000001;
int read(){
	char c=getchar();int d=0,f=1;
	for(;c<'0'||c>'9';c=getchar())if(c=='-')f=-1;
	for(;c>='0'&&c<='9';d=d*10+c-48,c=getchar());
	return d*f;
}
char Read(){
	char c=getchar();
	while(c<'0'||c>'1')c=getchar();
	return c;
}
char c1[N],c2[N];
int h1,w1,h2,w2,n1,n2;LL H,W,ans;
LL solve(int x1,int x2){
	LL i1=1,i2=1,res=0;
	while(i1<=w1&&i2<=w2){
		LL I1=i1*(W/w1),I2=i2*(W/w2);
		if(c1[(x1-1)*w1+i1]==c2[(x2-1)*w2+i2]){
			LL J1=I1-(W/w1),J2=I2-(W/w2);
			res+=min(I1,I2)-max(J1,J2);
		}
		if(I1==I2)i1++,i2++;else 
		if(I1<I2)i1++;else i2++;
	}
	return res;
}
int main(){
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
	h1=read(),w1=read();
	ref(i,1,h1)ref(j,1,w1)c1[(i-1)*w1+j]=Read();
	h2=read(),w2=read();
	ref(i,1,h2)ref(j,1,w2)c2[(i-1)*w2+j]=Read();
	H=(LL)h1*h2/__gcd(h1,h2);
	W=(LL)w1*w2/__gcd(w1,w2);
	LL i1=1,i2=1;
	while(i1<=h1&&i2<=h2){
		LL I1=i1*(H/h1),I2=i2*(H/h2);
		LL J1=I1-(H/h1),J2=I2-(H/h2);
		ans+=solve(i1,i2)*(min(I1,I2)-max(J1,J2));
		if(I1==I2)i1++,i2++;else
		if(I1<I2)i1++;else i2++;
	}
	printf("%lld\n",ans);
}