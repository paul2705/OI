#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

int ha,wa,hb,wb;
long long ans;
std::string sa,sb;

int gcd(int x,int y) {
	return x%y==0?y:gcd(y,x%y);
}

int main() {
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
	scanf("%d%d",&ha,&wa);
	std::cin>>sa;
	scanf("%d%d",&hb,&wb);
	std::cin>>sb;
	int lcm_h=ha*hb/gcd(ha,hb),lcm_w=wa*wb/gcd(wa,wb);
	int ya=lcm_w/wa,yb=lcm_w/wb;
	for (int i=0;i<lcm_h;i++) {
		int xa=i/(lcm_h/ha),xb=i/(lcm_h/hb);
		for (int j=0;j<lcm_w;j++)
			if (sa[xa*wa+j/ya]==sb[xb*wb+j/yb]) ans++;
	}
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
