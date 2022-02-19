#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
double l,r,m;
int n,s[100100];
double hmax[100100],qmin[100100],c[100100];
bool check(){
    for(int i=0;i<=n;i++) c[i]=s[i]-m*i;
    qmin[1]=c[1];
    for(int i=2;i<=n;i++) qmin[i]=min(qmin[i-1],c[i]);
    hmax[n-1]=c[n-1];
    for(int i=n-2;i>=1;i--) hmax[i]=max(hmax[i+1],c[i]);
    for(int i=2;i<n;i++)
        if (hmax[i]-qmin[i-1]>c[n]) return 0;
    return 1;
}
int main(){
    scanf("%d",&n);
    for(int i=1,x;i<=n;i++) scanf("%d",&x),s[i]=s[i-1]+x;
    l=0,r=1e4+100;
    for(int i=1;i<=60;i++){
        m=(l+r)/2;
        if (check()) l=m;
        else r=m;
    }
    printf("%.3lf",l);
    return 0;
}
