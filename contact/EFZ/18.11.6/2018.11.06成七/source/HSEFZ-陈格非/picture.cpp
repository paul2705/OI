#include <cstdio>
const int maxn = 1e6+10;
char s1[maxn],s2[maxn];
int h1,h2,w1,w2,ans;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
bool a1(int i,int j){return s1[i*w1+j]=='1';}
bool a2(int i,int j){return s2[i*w2+j]=='1';}
int main() {
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
	scanf("%d%d%s",&h1,&w1,s1);
	scanf("%d%d%s",&h2,&w2,s2);
	int h = h1*h2/gcd(h1,h2), w = w1*w2/gcd(w1,w2);
	int x1 = h/h1, y1 = w/w1, x2 = h/h2, y2 = w/w2;
	for (int i=0; i<h; i++)
		for (int j=0; j<w; j++)
			ans += a1(i/x1,j/y1)==a2(i/x2,j/y2);
	printf("%d\n",ans);
}
