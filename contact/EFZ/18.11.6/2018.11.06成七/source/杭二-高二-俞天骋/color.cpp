#include<cstdio>
int tot,hd,tl,rt,num[100001],p[100001],n,m,fa[100001],c[100001],ui,vi,nex[200001],fir[100001],sto[200001],ans[100001][3];
void addbian(int aa,int bb)
{
	tot++;
	nex[tot]=fir[aa];
	fir[aa]=tot;
	sto[tot]=bb;
}
bool jud(int x)
{
	int aa=fir[x];
	if((p[x]!=0)&&(p[x]!=rt))return(false);
	if(p[x]>0)num[rt]--;
	if(num[rt]==0)
	{
		num[rt]++;
		tl=x;
		return(true);
	}
	while(aa!=0)
	{
		if(sto[aa]!=fa[x])
		{
			fa[sto[aa]]=x;
			if(jud(sto[aa]))
			{
				if(p[x]>0)num[p[x]]++;
				return(true);
			}
		}
		aa=nex[aa];
	}
	if(p[x]>0)num[p[x]]++;
	return(false);
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<=m;i++)num[i]=0;
	for(int i=1;i<=m;i++)c[i]=1;
	for(int i=1;i<=n;i++)num[p[i]]++;
	for(int i=2;i<=n;i++)
	{
		scanf("%d%d",&ui,&vi);
		addbian(ui,vi);
		addbian(vi,ui);
	}
	for(int i=1;i<=m;i++)
	{
		int nw;
		for(int j=1;j<=m;j++)if(c[j])nw=j;
		hd=tl=1;
		for(int j=1;j<=n;j++)if(p[j]!=0)
		{
			fa[j]=j;
			rt=p[j];
			if(jud(j))
			{
				nw=rt;
				hd=j;
				break;
			}
		}
		for(int j=1;j<=n;j++)if(p[j]==rt)p[j]=0;
		ans[i][0]=rt;ans[i][1]=hd;
		ans[i][2]=tl;
		c[rt]=0;
	}
	for(int i=m;i>=1;i--)printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
}
