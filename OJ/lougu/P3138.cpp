#include<bits/stdc++.h>
using namespace std;

void chmin(int &x,int y)
{
    if(x>y)x=y;
}

const int N=1005;
int n,i,u;
int px[N],py[N];
int id[N];

bool py_xiao(int x,int y) 
{
   return py[x]<py[y];
}
bool px_xiao(int x,int y) 
{
   return px[x]<px[y];
}
int lisan_py()
{
    for(i=1;i<=n;++i)id[i]=i;
    sort(id+1,id+n+1,py_xiao);
    int now=0,top=0;
    for(i=1;i<=n;++i)
    {
      int x=id[i];
      if(py[x]!=now){now=py[x];++top;}
      py[x]=top;
    }
    return top;
}

#define cl (i<<1)
#define cr (cl+1)
int al[N*3],ar[N*3],d;
void init(int *a)
{
    for(i=1;i<=n;++i)++a[d+py[i]];
    for(i=u+d>>1;i;--i) a[i]=a[cl]+a[cr];
}
void add(int *a,int i,int w)
{
    for(i+=d;i;i>>=1) a[i]+=w;
}
int erfen()
{
    i=1;
    int all=0,alr=0,arl=0,arr=0;
    while(i<=d)
    {
        int mxl=max(all+al[cl],arl+ar[cl]),mxr=max(alr+al[cr],arr+ar[cr]);
        //假设选择[l,mid],[mid+1,r]来划分 左右的max 
        if(mxl<=mxr) { all+=al[cl];arl+=ar[cl];i=cr; }
        else { alr+=al[cr];arr+=ar[cr];i=cl; }
    }
    int mxl=max(max(all+al[i],arl+ar[i]),max(all,arr)),
        mxr=max(max(alr+al[i],arr+al[i]),max(all,arl));
    //i分在左/右 
    return min(mxl,mxr); 
}

int main()
{
//    freopen("1.in","r",stdin);
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d%d",px+i,py+i);

    u=lisan_py();
    for(d=1;d<u;d<<=1);d-=1;
    init(ar);

    sort(id+1,id+n+1,px_xiao);
    int ans=n;
    for(i=1;i<=n;++i)
    {
        int x=id[i];
        add(ar,py[x],-1);
        add(al,py[x],1);
        chmin(ans,erfen());
    }
    printf("%d\n",ans);
}
