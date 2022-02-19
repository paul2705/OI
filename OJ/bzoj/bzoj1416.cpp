#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define mo 10000
using namespace std;
int f[20005],p[20005],cnt0[20005],cnt1[20005],a[20005];
int t,n,d,tot,x,y,k;
void mult(int h[]){
    int a[3005];
    memset(a,0,sizeof(a));
    a[0]=a[1]=1;
    for (int i=1;i<=p[0];i++)
        for (int j=1;j<=h[i];j++){
            for (int k=1;k<=a[0];k++) a[k]*=p[i];
            for (int k=1;k<=a[0];k++){
                a[k+1]+=a[k]/mo;
                a[k]%=mo;
            }
            if (a[a[0]+1]) a[0]++;
        }
    printf("%d",a[a[0]]);
    for (int i=a[0]-1;i>=1;i--) printf("%04d",a[i]);
}
void chai(int x,int h[]){
    for (int i=1;i<=p[0];i++)
        while (x%p[i]==0){
            x/=p[i];
            h[i]++;
        }
}
int main(){
    for (int i=2;i<=20000;i++)
        if (!f[i]){
            p[++p[0]]=i;
            for (int j=i;j*i<=20000;j++) f[i*j]=1;
        }
    scanf("%d%d%d",&t,&n,&d);
    for (int i=1;i<=t;i++){
        scanf("%d",&a[i]);
        tot+=a[i];
    }
    while (n--){
        scanf("%d%d",&x,&y);
        chai(a[y],cnt0);
        chai(tot,cnt1);
        a[y]+=d;
        tot+=d;
    }
    for (int i=1;i<=p[0];i++){
        k=min(cnt0[i],cnt1[i]);
        cnt0[i]-=k;
        cnt1[i]-=k;
    }
    mult(cnt0);
    printf("/");
    mult(cnt1);
}
