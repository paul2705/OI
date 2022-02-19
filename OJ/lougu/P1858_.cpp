#include<cstdio>
#include<cstring>
int f[5010][60],ans=0;
int k,v,n,w[220],c[220],t[60];
int main(){
    memset(f,-63,sizeof(f));
    scanf("%d%d%d",&k,&v,&n);
    for (int i=1;i<=n;i++) scanf("%d%d",&w[i],&c[i]);
    f[0][1]=0;
    for (int i=1;i<=n;i++)
        for (int j=v;j>=w[i];j--){
            int t1=1,t2=1,t[60],len=0;
            while (t1+t2<=k+1){
        if (f[j][t1]>f[j-w[i]][t2]+c[i]) 
            t[++len]=f[j][t1++];
                else t[++len]=f[j-w[i]][t2++]+c[i];
            }
            for (int K=1;K<=k;K++){
		f[j][K]=t[K];
		printf("%d %d %d\n",j,k,f[j][k]);
		}
        }
    for (int i=1;i<=k;i++) ans+=f[v][i];
    printf("%d",ans);
}
