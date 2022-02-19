#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#define maxx 1000007
using namespace std;
inline int read(){
	int X=0,w=1;
	char ch=0;
	while(ch<'0'||ch>'9'){if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') X=(X<<3)+(X<<1)+ch-'0',ch=getchar();
	return X*w;
}
long long n1,m1,n2,m2,z1,z2,w1,w2;
//c[maxx],poi1[2][maxx],poi2[2][maxx],len2[maxx];
char s1[maxx],s2[maxx];
bool z[1007][1007];
/*
struct mmp{
	long long x,xx;
	int y;
	bool z;
}hp[maxx*2],sp[maxx*2];
inline bool ctm(const mmp &x,const mmp &y){
	return x.x<y.x;
}*/
inline int zb1(int x,int y){
	return (x-1)*n1+y;
}
inline int zb2(int x,int y){
	return (x-1)*n2+y;
}/*
inline void add1(int x,int y){
	while(x<=w2){
//		cout<<x<<endl;
		c[x]^=1;
		x+=(x)&(-x);
	}
}
inline void add2(int x,int y){
	while(x<=w2){
		c[x]^=1;
		x+=(x)&(-x);
	}
}
inline int que(int x){
	int a=0;
	while(x>0){
		a^=c[x];
		x-=(x)&(-x);
	}
	return a;
}*/
int main(){
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
	n1=read(),m1=read();
	scanf("%s",s1+1);
	n2=read(),m2=read();
	scanf("%s",s2+1);
	long long h=n1*n2/__gcd(n1,n2),w=m1*m2/__gcd(m1,m2);
	long long st1=h/n1,st2=w/m1;
	for(int i=1;i<=n1;i++){
		for(int j=1;j<=m1;j++){
			if(s1[zb1(i,j)]=='1'){
				for(int k=(i-1)*st1+1;k<=i*st1;k++){
					for(int p=(j-1)*st2+1;p<=j*st2;p++){
						z[k][p]^=1;
					}
				}
			}
		}
	}
	st1=h/n2,st2=w/m2;
	for(int i=1;i<=n2;i++){
		for(int j=1;j<=m2;j++){
			if(s2[zb2(i,j)]=='1'){
				for(int k=(i-1)*st1+1;k<=i*st1;k++){
					for(int p=(j-1)*st2+1;p<=j*st2;p++){
						z[k][p]^=1;
					}
				}
			}
		}
	}
	long long snd=0;
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			if(z[i][j]==0){
				snd++;
			}
		}
	}
	printf("%lld",snd);
/*	for(int i=h/n1;i;i--){
		hp[++z1]=(mmp){n1*i-n1+1,n1*i-n1+1,i,0};
	}
	for(int i=h/n2;i;i--){
		hp[++z1]=(mmp){n2*i-n2+1,n2*i-n2+1,i,1};
	}
	for(int i=w/m1;i;i--){
		sp[++z2]=(mmp){m1*i-m1+1,m1*i-m1+1,i,0};
	}
	for(int i=w/m2;i;i--){
		sp[++z2]=(mmp){m2*i-m2+1,m2*i-m2+1,i,1};
	}
	sort(hp+1,hp+z1+1,ctm);
	sort(sp+1,sp+z2+1,ctm);
	for(int i=1;i<=z1;i++){
		if(hp[i].x!=hp[i-1].x){
			c[i]=++w1;
		}
		else{
			c[i]=w1;
		}
	}
	for(int i=1;i<=z1;i++){
		hp[i].x=c[i];
		poi1[hp[i].z][hp[i].y]=c[i];
	}
	for(int i=1;i<=z2;i++){
		if(sp[i].x!=sp[i-1].x){
			c[i]=++w2;
		}
		else{
			c[i]=w2;
		}
	}
	for(int i=1;i<=z2;i++){
		sp[i].x=c[i];len2[c[i]]=sp[i].xx;
		poi2[sp[i].z][sp[i].y]=c[i];
//		cout<<"poi2["<<sp[i].z<<"]["<<sp[i].y<<"]="<<poi2[sp[i].z][sp[i].y]<<endl;
	}
	memset(c,0,sizeof(c));
	poi1[0][h/n1+1]=poi1[1][h/n2+1]=w1+1;
	poi2[0][w/m1+1]=poi2[1][w/m2+1]=w2+1;
//	cout<<"w "<<w1<<" "<<w2<<" "<<m2<<" "<<poi2[1][3]<<endl;
	long long ans=0;sp[z1+1].xx=h+1;
	for(int i=1;i<=z1;i++){
//		cout<<i<<endl;
		if(i>1||i==z1+1){
			for(int j=2;j<=w2;j++){
				int zz=que(j)^que(j-1);
				if(zz){
					ans+=(len2[j]-len2[j-1]+1)*(sp[i].xx-sp[i-1].xx);
				}
			}
			cout<<ans<<endl;
			if(i==z1+1){
				break;
			}
		}
//		puts("nan");
		if(hp[i].z==0){
			if(hp[i].y>1){
				for(int j=1;j<=w/m1;j++){
					if(s1[zb1(hp[i].y-1,j)]=='1'){
						add1(poi2[0][j],1);
						add1(poi2[0][j+1],1);
					}
				}
			}
		}
		else{
			if(hp[i].y>1){
				for(int j=1;j<=w/m2;j++){
					if(s2[zb2(hp[i].y-1,j)]=='1'){
						add1(poi2[1][j],1);
						add1(poi2[1][j+1],1);
					}
				}
			}
		}
//		puts("dsn");
		if(hp[i].z==0){
			for(int j=1;j<=w/m1;j++){
				if(s1[zb1(hp[i].y,j)]=='1'){
					add1(poi2[0][j],1);
					add1(poi2[0][j+1],1);
				}
			}
		}
		else{
			for(int j=1;j<=w/m2;j++){
//				cout<<"j "<<j<<endl;
				if(s1[zb2(hp[i].y,j)]=='1'){
//					cout<<"s "<<j<<" "<<poi2[1][j+1]<<endl;
					add1(poi2[1][j],1);
					add1(poi2[1][j+1],1);
				}
			}
		}
//		puts("ewq");
	}
	printf("%lld",ans);*/
	return 0;
}
