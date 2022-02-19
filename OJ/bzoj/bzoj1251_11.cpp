#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define inf 0x3f3f3f3f
#define A printf("A")
#define C printf(" ")
using namespace std;
const int N=5e4+2;
template<typename _Tp>inline void IN(_Tp&dig){
    char c;bool flag=0;dig=0;
    while(c=getchar(),!isdigit(c))if(c=='-')flag=1;
    while(isdigit(c))dig=dig*10+c-'0',c=getchar();
    if(flag)dig=-dig;
}int f[N],s[N],v[N],ch[N][2],add[N],rev[N],mx[N];
int n,m,size,root,num[N];
inline int chk(int x){return ch[f[x]][1]==x;}
inline void pushup(int x){
    s[x]=s[ch[x][1]]+s[ch[x][0]]+1;
    mx[x]=max(v[x],max(mx[ch[x][1]],mx[ch[x][0]]));
}
inline void pushdown(int x){
    int &l=ch[x][0],&r=ch[x][1];
    if(add[x]){
        if(l)add[l]+=add[x],v[l]+=add[x],mx[l]+=add[x];
        if(r)add[r]+=add[x],v[r]+=add[x],mx[r]+=add[x];
    }if(rev[x])rev[l]^=1,rev[r]^=1,swap(l,r);
    rev[x]=add[x]=0;return;
}
inline void rotate(int x){
    int y=f[x],z=f[y],k=chk(x),v=ch[x][k^1];
    pushdown(x),pushdown(y);
    ch[y][k]=v,f[v]=y,ch[z][chk(y)]=x,f[x]=z;
    ch[x][k^1]=y,f[y]=x;pushup(x),pushup(y);return;
}
inline void Splay(int x,int goal=0){
    while(f[x]!=goal){if((f[f[x]])!=goal)
        if(chk(x)==chk(f[x]))rotate(f[x]);
        else rotate(x);
        rotate(x);
    }if(!goal)root=x;
}
inline int build(int l,int r,int fa){
    if(l>r)return 0;int x=++size,mid=(l+r)>>1;
    f[x]=fa,v[x]=mx[x]=num[mid];
    ch[x][0]=build(l,mid-1,x);ch[x][1]=build(mid+1,r,x);
    pushup(x);return x;
}
inline int Kth(int x){
    int pos=root;
    while(pos){
        pushdown(pos);
        if(x<=s[ch[pos][0]])pos=ch[pos][0];
        else{
            x-=s[ch[pos][0]]+1;
            if(!x)return pos;pos=ch[pos][1];
        }
    }return 0;
}
inline void get(int l,int r)
{l=Kth(l),r=Kth(r+2);Splay(l,0),Splay(r,l);}
int main(){
	freopen("bzoj1251.in","r",stdin);
	freopen("bzoj1251_.out","w",stdout);
	IN(n),IN(m);mx[0]=num[1]=num[n+2]=-2e9;root=build(1,n+2,0);
    for(register int K,L,R,V,S,i=1;i<=m;++i){
        IN(K),IN(L),IN(R),get(L,R),S=ch[ch[root][1]][0];
        if(K==1)IN(V),add[S]+=V,mx[S]+=V,v[S]+=V;
        else if(K==2)rev[S]^=1;
        else printf("%d\n",mx[S]);
    }
	fclose(stdin); fclose(stdout);
	return 0;
}
