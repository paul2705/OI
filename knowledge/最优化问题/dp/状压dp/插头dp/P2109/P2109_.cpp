#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#define fp(i,a,b) for(register int i=a,I=b+1;i<I;++i)
#define fd(i,a,b) for(register int i=a,I=b-1;i>I;--i)
#define go(u) for(register int i=fi[u],v=e[i].to;i;v=e[i=e[i].nx].to)
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
template<class T>inline bool cmax(T&a,const T&b){return a<b?a=b,1:0;}
template<class T>inline bool cmin(T&a,const T&b){return a>b?a=b,1:0;}
using namespace std;
const int K=6,S=55,P=65521,T[]={1,1,1,3,16,125};
typedef long long ll;
int k,Cnt,ans,sum[K],fa[K],f[S],sta[S],pos[1<<16];ll n;
inline int pls(int a,int b){return a+=b,a<P?a:a-P;}
struct matrix{
    int a[S][S];
    matrix(int x=0){memset(a,0,sizeof a);if(x)fp(i,1,Cnt)a[i][i]=1;}
    inline int*operator[](int x){return a[x];}
    inline matrix operator*(matrix b){
        matrix c;
        fp(i,1,Cnt)fp(k,1,Cnt)if(a[i][k])fp(j,1,Cnt)
            c[i][j]=pls(c[i][j],(ll)a[i][k]*b[k][j]%P);
        return c;
    }
    inline matrix operator^(ll b){
        matrix x(1),a=*this;
        for(;b;b>>=1,a=a*a)if(b&1)x=x*a;
        return x;
    }
}g;
inline bool chk(int s){
    int tp=1;
    for(int i=0;i<3*k;tp|=1<<(((s>>i)&7)),i+=3)
        fp(j,0,((s>>i)&7)-1)if(!(tp&(1<<j)))return 0;
    return 1;
}
void dfs(int d,int s){
    if(d==k){if(chk(s))sta[++Cnt]=s,pos[s]=Cnt;return;}
    fp(i,1,k)dfs(d+1,s|(i<<(3*d)));
}
int gf(int x){return fa[x]==x?x:fa[x]=gf(fa[x]);}
inline void Getnx(int i,int s,int nw){
    fp(j,0,k)fa[j]=j;
    fp(j,0,k)fp(l,j+1,k)
        if(((nw>>(3*j))&7)==((nw>>(3*l))&7))fa[gf(j)]=gf(l);
    fp(j,0,k)if(s&(1<<j)){
        if(gf(j)^gf(k))fa[fa[j]]=k;
        else return;
    }
    int tp=0,nx=0,fg=0;
    fp(j,1,k)if(gf(0)==gf(j)){fg=1;break;};
    if(!fg)return;
    fp(j,0,k-1)if(!(nx&(7<<(j*3)))){
        nx|=++tp<<(j*3);
        fp(l,j+1,k-1)if(gf(j+1)==gf(l+1))
            nx|=tp<<(l*3);
    }
    ++g[i][pos[nx]];
}
int main(){
///    #ifndef ONLINE_JUDGE
//     file("s");
  //  #endif
    scanf("%d%lld",&k,&n);dfs(0,1);
    fp(i,1,Cnt){
        f[i]=1;int nw=sta[i];
        memset(sum,0,sizeof sum);
        fp(j,0,k-1)++sum[(nw>>(j*3))&7];
        fp(j,1,k)f[i]*=T[sum[j]];
        fp(s,0,(1<<k)-1)Getnx(i,s,nw);
    }
	cout<<Cnt<<endl;
	for (int i=1;i<=Cnt;i++){
//		cout<<sta[i]<<endl;
		for (int j=1;j<=Cnt;j++) cout<<g[i][j]<<" ";
		cout<<endl;
	}
	g=g^(n-k);
	for (int i=1;i<=Cnt;i++) cout<<f[i]<<" ";
	cout<<endl;
	fp(i,1,Cnt)ans=pls(ans,f[i]*g[i][1]%P);
    printf("%d",ans);
return 0;
}
