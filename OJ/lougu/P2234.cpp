#include <cstdio>
#include <algorithm>
#define ri register int
#define getchar() (S==T&&(T=(S=BB)+fread(BB,1,1<<15,stdin),S==T)?EOF:*S++)
char BB[1<<20],*S=BB,*T=BB;
using namespace std;
int n,sum;
inline int read() {
    int num=0,w=1; char ch=0;
    while(ch<'0'||ch>'9') {if(ch=='-') w=-1;ch=getchar(); }
    while(ch>='0'&&ch<='9') num=(num<<3)+(num<<1)+ch-'0',ch=getchar();
    return num*w;
}
struct A{
    int num,day;
}a[100000];
bool cmp(A a,A b){ return a.num<b.num; }
inline int check(int x){
    int p=2147483647,t=2147483647;
    if(a[x].day==1) return a[x].num;
    for(ri i=x-1;i>=1;--i)
        if(a[i].day<a[x].day){
		p=(a[i].num>a[x].num)?a[i].num-a[x].num:a[x].num-a[i].num;
		break;
	}
    for(ri i=x+1;i<=n;++i)
        if(a[i].day<a[x].day){
		t=(a[i].num>a[x].num)?a[i].num-a[x].num:a[x].num-a[i].num;
		break;
	}
    return (p>t)?t:p;
}
int main(){
    n=read();
    for(ri i=1;i<=n;++i)
        a[i].num=read(),a[i].day=i;
    sort(a+1,a+1+n,cmp);
    for(ri i=1;i<=n;++i)
        sum+=check(i);
    printf("%d",sum);
    return 0;
}

