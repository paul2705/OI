#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e4+5;
int n;
struct rec{
    int x,y;
} a[MAXN],b[MAXN];
int s1[MAXN],s2[MAXN];
int top1,top2;
int use[MAXN];
bool check1(int i,int j,int k){
    int x=a[i].x,y=a[i].y;
    int xx=a[j].x,yy=a[j].y;
    int xxx=a[k].x,yyy=a[k].y;
    return (yy-y)*(xxx-x)<=(yyy-y)*(xx-x);
}
bool check2(int i,int j,int k){
    int x=a[i].x,y=a[i].y;
    int xx=a[j].x,yy=a[j].y;
    int xxx=a[k].x,yyy=a[k].y;
    return (yy-y)*(xxx-x)>=(yyy-y)*(xx-x);
}
bool check3(int i,int j,int k){
    int x=a[i].x,y=a[i].y;
    int xx=b[j].x,yy=b[j].y;
    int xxx=a[k].x,yyy=a[k].y;
    return (yy-y)*(xxx-xx)<=(yyy-yy)*(xx-x);
}
bool check4(int i,int j,int k){
    int x=a[i].x,y=a[i].y;
    int xx=b[j].x,yy=b[j].y;
    int xxx=a[k].x,yyy=a[k].y;
    return (yy-y)*(xxx-xx)>=(yyy-yy)*(xx-x);
}
bool les(int i,int j){
    int x=b[i].x,y=b[i].y;
    int xx=a[j].x,yy=a[j].y;
    if (x!=xx) return x<xx;
    return y<yy;
}
bool cmp(rec a,rec b){ return a.x==b.x?a.y<b.y:a.x<b.x; }
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
    for (int i=1;i<=n;i++) scanf("%d%d",&b[i].x,&b[i].y);
    sort(a+1,a+n+1,cmp); sort(b+1,b+n+1,cmp);
    s2[++top2]=s1[++top1]=1;
    for (int i=2;i<=n;i++){
        while (top1>1&&check1(s1[top1-1],s1[top1],i)) top1--;
        s1[++top1]=i;
    }
    for (int i=2;i<=n;i++){
        while (top2>1&&check2(s2[top2-1],s2[top2],i)) top2--;
        s2[++top2]=i;
    }
    int l=1,r=2,pos=1;
    while (les(pos,s1[1])) pos++;
    for (;pos<=n;pos++){
        while (r<=n&&!les(pos,s1[r])) l++,r++;
        if (r>n) use[pos]=0;
        if (check3(s1[l],pos,s1[r])) use[pos]++;
    }
    pos=l=1; r=2;
    while (les(pos,s2[1])) pos++;
    for (;pos<=n;pos++){
        while (r<=n&&!les(pos,s2[r])) l++,r++;
        if (r>n) use[pos]=0;
        if (check4(s2[l],pos,s2[r])) use[pos]++;
    }
    int ans=0;
    for (int i=1;i<=n;i++){
        if (use[i]==2) ans++;
    }
    printf("%d\n",ans);
    return 0;
}

