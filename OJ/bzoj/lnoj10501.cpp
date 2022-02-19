#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=5e4+5;
const double eps=1e-8;
int n;
struct rec{
    double x,y;
} a[MAXN],b[MAXN];
int s1[MAXN],s2[MAXN];
int top1,top2;
int use[MAXN];
bool fncmp(double a,double b){
//	printf("%.8lf %.8lf\n",a,b);
	if (fabs(a-b)<=eps) return 1;
	else return a<b;
}
bool fxcmp(double a,double b){
	if (fabs(a-b)<=eps) return 1;
	else return a>b;
}
double slop(int i,int j){
    double x=a[i].x,y=a[i].y;
    double xx=a[j].x,yy=a[j].y;
//	cout<<(yy-y)/(xx+eps-x)<<endl;
	if (fncmp(xx,x)&&fxcmp(xx,x)) return 1/eps;
	else return (yy-y)/(xx-x);
}
bool les(int i,int j){
    double x=b[i].x,y=b[i].y;
    double xx=a[j].x,yy=a[j].y;
    if (x!=xx) return x<xx;
    return y<yy;
}
bool cmp(rec a,rec b){ return a.x==b.x?a.y<b.y:a.x<b.x; }
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%lf%lf",&a[i].x,&a[i].y);
    for (int i=1;i<=n;i++) scanf("%lf%lf",&b[i].x,&b[i].y);
    sort(a+1,a+n+1,cmp); sort(b+1,b+n+1,cmp);
    s2[++top2]=s1[++top1]=1;
    for (int i=2;i<=n;i++){
        while (top1>1&&fncmp(slop(s1[top1-1],s1[top1]),slop(s1[top1-1],i))) top1--;
        s1[++top1]=i;
    }
//	for (int i=1;i<=top1;i++) cout<<s1[i]<<" ";
//	cout<<endl;
	for (int i=2;i<=n;i++){
        while (top2>1&&fxcmp(slop(s2[top2-1],s2[top2]),slop(s2[top2-1],i))) top2--;
        s2[++top2]=i;
    }
	int l=1,r=2,pos=1;
    while (les(pos,s1[1])) pos++;
    for (;pos<=n;pos++){
		while (r<=n&&!les(pos,s1[r])) l++,r++;
        if (r>n){ use[pos]=0; continue;}
        if (fncmp(slop(s1[l],pos),slop(s1[r],pos))) use[pos]++;
//		cout<<pos<<" "<<use[pos]<<endl;
    }
    pos=l=1; r=2;
    while (les(pos,s2[1])) pos++;
    for (;pos<=n;pos++){
        while (r<=n&&!les(pos,s2[r])) l++,r++;
        if (r>n) use[pos]=0;
        if (fxcmp(slop(s2[l],pos),slop(s2[r],pos))) use[pos]++;
    }
    int ans=0;
    for (int i=1;i<=n;i++){
//		cout<<use[i]<<endl;
		if (use[i]==2) ans++;
    }
    printf("%d\n",ans);
    return 0;
}


