#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#define inf 99999999
using namespace std;
int m,len;
char s[1010];
int a[1010];
int sum[1010][1010],f[1010][100];
int main()
{
    memset(f,0x7f7f7f,sizeof(f));
    scanf("%s%d",s,&m);
    int len=strlen(s);
    for(int i=0;i<len;i++) a[i+1]=s[i]-'0';
    for(int i=1;i<=len;i++)
     for(int j=i;j<=len;j++)
      sum[i][j]=(sum[i][j-1]*10+a[j])%m;//预处理出每个区间取mod后的值 
    for(int i=1;i<=len;i++) f[i][sum[1][i]]=1;  
    for(int i=1;i<=len;i++)
     for(int j=1;j<i;j++)
      for(int k=0;k<=m-1;k++) f[i][(k*sum[j+1][i])%m]=min(f[i][(k*sum[j+1][i])%m],f[j][k]+1);
    for(int i=0;i<m;i++) if(f[len][i]<inf){printf("%d %d ",i,f[len][i]-1);break;}   
    for(int i=m-1;i>=0;i--) if(f[len][i]<inf){printf("%d %d",i,f[len][i]-1);break;}   
    return 0;
}
