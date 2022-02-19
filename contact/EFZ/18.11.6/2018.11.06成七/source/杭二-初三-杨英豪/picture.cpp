#include<bits/stdc++.h>
using namespace std;
int H1,W1,H2,W2,H,W;
int CH1,CW1,CH2,CW2;
long long sh,sw,eh,ew,ssh,ssw,eeh,eew;
int Sh,Sw,Eh,Ew;
long long SH,SW,EH,EW;
char ch;
bool M1[1100000],M2[1100000];
long long ans = 0;
inline int Gcd(int u,int v)
{
	if(v == 0) return u;
	return Gcd(v,u%v);
}
int main()
{
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
	scanf("%d %d\n",&H1,&W1);
	for(int i = 1;i<=H1;i++)
		for(int j = 1;j<=W1;j++)
		{
			ch =  getchar();
			if(ch!='1'&&ch!='0') ch = getchar();
			M1[(i-1)*W1 + j] = ch - '0';
		}
	scanf("%d %d\n",&H2,&W2);
	for(int i = 1;i<=H2;i++)
		for(int j = 1;j<=W2;j++)
		{
			ch =  getchar();
			if(ch!='1'&&ch!='0') ch = getchar();
			M2[(i-1)*W2 + j] = ch - '0';
		}
	H = Gcd(H1,H2);
	W = Gcd(W1,W2);
	CH1 = H2 / H,CW1 = W2 / W;
	CH2 = H1 / H,CW2 = W1 / W;
	for(int i = 1;i<=H1;i++)
		for(int j = 1;j<=W1;j++)
		{
			bool x = M1[(i-1) * W1 + j];
			sh = 1ll * (i-1) * CH1 + 1ll;
			eh = 1ll * i * CH1;
			sw = 1ll * (j-1) * CW1 + 1ll;
			ew = 1ll * j * CW1;
			Sh = (sh-1) / CH2 + 1;
			Eh = (eh-1) / CH2 + 1;
			Sw = (sw-1) / CW2 + 1;
			Ew = (ew-1) / CW2 + 1;
			for(int ii = Sh;ii<=Eh;ii++)
				for(int jj = Sw;jj<=Ew;jj++)
				{
					bool y = M2[(ii-1)*W2+jj];  
					if(x != y) continue;
					else
					{
						ssh = 1ll * (ii-1) * CH2+ 1ll;
						eeh = 1ll * ii * CH2;
						ssw = 1ll * (jj-1) * CW2 + 1ll;
						eew = 1ll * jj * CW2;
						SH = max(ssh,sh);
						EH = min(eeh,eh);
						SW = max(ssw,sw);
						EW = min(ew,eew);
						ans += (EH - SH + 1) * (EW - SW + 1);
					}
				}
		}
	printf("%lld\n",ans);
	return 0;
}
