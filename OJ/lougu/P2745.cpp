#include<set>
#include<map>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath> 
#include<iostream>
#include<algorithm>
using namespace std;
char ch;
int x,y,x1,y12;
int n;
struct node{
    int x1,x2,y11,y2;
    int id,deep,flag;
} a[2500];
map<char,int> a1;
int max1,min1;
int zx[2500],lx,ux[45000];
int zy[2500],ly,uy[45000];
int f[250][250];
void sum(int x){
    memset(f,0,sizeof(f));
    lx=0;ly=0;
    for (int i=1;i<=n;i++){
        if (a[i].flag==0||a[i].deep<a[x].deep) continue;
        zx[++lx]=a[i].x1;zx[++lx]=a[i].x2; 
        zy[++ly]=a[i].y11;zy[++ly]=a[i].y2;
    }
    sort(zx+1,zx+lx+1);
    sort(zy+1,zy+ly+1); 
    int t=0;
    for (int i=1;i<=lx;i++){
        if (zx[i]!=zx[i-1]){
            t++;
            zx[t]=zx[i];
            ux[zx[i]]=t;
        }
    } 
    lx=t; 
    t=0;
    for (int i=1;i<=ly;i++){
        if (zy[i]!=zy[i-1]){
            t++;
            zy[t]=zy[i];
            uy[zy[i]]=t; 
        }
    } 
    ly=t;
    for (int i=ux[a[x].x1];i<=ux[a[x].x2]-1;i++)
        for (int j=uy[a[x].y11];j<=uy[a[x].y2]-1;j++)
            f[i][j]=1;
    for (int i=1;i<=n;i++)
        if (a[i].deep>a[x].deep&&a[i].flag==1){
            for (int j=ux[a[i].x1];j<=ux[a[i].x2]-1;j++)
                for (int k=uy[a[i].y11];k<=uy[a[i].y2]-1;k++)
                f[j][k]=0;
        }
    double sum1=0.0;
    for (int i=1;i<lx;i++)
        for (int j=1;j<ly;j++){
            sum1+=f[i][j]*(zx[i+1]-zx[i])*(zy[j+1]-zy[j]);
        }
    double x1=100*(double)(sum1)/(double)((a[x].x2-a[x].x1)*(a[x].y2-a[x].y11));
    printf("%.3lf\n",x1);
    return;
}
int main(){
    while (scanf("%c",&ch)!=EOF){
        if (ch=='w'){
            scanf("(%c,%d,%d,%d,%d)",&ch,&x,&y,&x1,&y12);
            n++; 
            a1[ch]=n;
            a[n].x1=min(x,x1);a[n].x2=max(x,x1);
            a[n].y11=min(y,y12);a[n].y2=max(y,y12);
            a[n].id=ch;a[n].flag=1;
            max1++;
            a[n].deep=max1;
        } else
        if (ch=='t'){
            scanf("(%c)",&ch);
            a[a1[ch]].deep=++max1;
        } else
        if (ch=='b'){
            scanf("(%c)",&ch);
            a[a1[ch]].deep=--min1;
        } else
        if (ch=='d'){
            scanf("(%c)",&ch);
            a[a1[ch]].flag=0;
        } else
        if (ch=='s'){
            scanf("(%c)",&ch);
            sum(a1[ch]); 
        } 
        getchar();getchar(); 
    }
    return 0;
}
