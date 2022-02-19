#include<cstdio>
#include<cstring> 
#include<vector>
using namespace std;

char s[1000010],S[1000010];
vector<bool> b[1000010],B[1000010];
int h,w,H,W,lh,lH,tmp,l,lw,lW,siz;
long long ans,la,sum[1000010];

int gcd(int a,int b) {return (!b)?a:gcd(b,a%b);}

long long query(long long l,long long r)
{
	long long ans,bel=(l-1)/lw+1,ber=(r-1)/lw+1;
	if (bel==ber) return (r-l+1)*(sum[bel]-sum[bel-1]);
	ans=(bel*lw-l+1)*(sum[bel]-sum[bel-1])+(r-(ber-1)*lw)*(sum[ber]-sum[ber-1]);
	ans+=(sum[ber-1]-sum[bel])*lw;
	return ans;
}

int main()
{
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
	scanf("%d%d",&h,&w);
	scanf("%s",s);
	scanf("%d%d",&H,&W);
	scanf("%s",S);
	for (int i=0; i<=1000000; i++) b[i].clear(),B[i].clear();
	if (1ll*h*H/gcd(h,H)>1000000ll)
	{
		if (w<W)
		{
			for (int i=1; i<=h; i++)
				for (int j=1; j<=w; j++)
					b[j].push_back(s[(i-1)*w+j-1]=='1');
			tmp=h; h=w; w=tmp;
			for (int i=1; i<=H; i++)
				for (int j=1; j<=W; j++)
					B[j].push_back(S[(i-1)*W+j-1]=='1');
			tmp=H; H=W; W=tmp;
		} else
		{
			for (int i=1; i<=H; i++)
				for (int j=1; j<=W; j++)
					b[j].push_back(S[(i-1)*W+j-1]=='1');
			for (int i=1; i<=h; i++)
				for (int j=1; j<=w; j++)
					B[j].push_back(s[(i-1)*w+j-1]=='1');
			tmp=h; h=W; W=tmp;
			tmp=H; H=w; w=tmp;
		}
	} else
	{
		if (h<H)
		{
			for (int i=1; i<=h; i++)
				for (int j=1; j<=w; j++)
					b[i].push_back(s[(i-1)*w+j-1]=='1');
			for (int i=1; i<=H; i++)
				for (int j=1; j<=W; j++)
					B[i].push_back(S[(i-1)*W+j-1]=='1');
		} else
		{
			for (int i=1; i<=H; i++)
				for (int j=1; j<=W; j++)
					b[i].push_back(S[(i-1)*W+j-1]=='1');
			for (int i=1; i<=h; i++)
				for (int j=1; j<=w; j++)
					B[i].push_back(s[(i-1)*w+j-1]=='1');
			tmp=h; h=H; H=tmp;
			tmp=w; w=W; W=tmp;
		}
	}
	l=1ll*h*H/gcd(h,H);
	lw=W/gcd(w,W);
	lW=w/gcd(w,W);
	lh=lH=0; ans=0;
	for (int i=0; i<l; i++)
	{
		if (i%(l/h)!=0&&i%(l/H)!=0) ans+=la; else
		{
			la=0;
			if (i%(l/h)==0)
			{
				lh++;
				siz=b[lh].size(); sum[0]=0;
				for (int j=0; j<siz; j++)
					if (b[lh][j]) sum[j+1]=sum[j]+1; else sum[j+1]=sum[j];
			}
			if (i%(l/H)==0) lH++;
			siz=B[lH].size();
			for (int j=0; j<siz; j++) 
				if (B[lH][j]) la+=query(1ll*lW*j+1,1ll*lW*(j+1));
				else la+=1ll*lW-query(1ll*lW*j+1,1ll*lW*(j+1));
			ans+=la;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
