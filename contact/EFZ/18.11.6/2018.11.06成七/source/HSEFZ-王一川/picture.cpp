#include<cstdio>
using namespace std;

int w1,h1,w2,h2,w,h;
char a[40][40],b[40][40];
char c[1000][1000],d[1000][1000];
int i,j;
int ans;




int gcd(int aa,int bb) {if (aa==0) return bb;return gcd(bb%aa,aa);}



int main() {
freopen("picture.in","r",stdin);
freopen("picture.out","w",stdout);
scanf("%d%d\n",&h1,&w1);
for (i=1;i<=h1;i++) for (j=1;j<=w1;j++) {scanf("%c",&a[i][j]);/*printf("%c",a[i][j]);*/}
scanf("%d%d\n",&h2,&w2);
for (i=1;i<=h2;i++) for (j=1;j<=w2;j++) {scanf("%c",&b[i][j]);/*printf("%c",b[i][j]);*/}
w=gcd(w1,w2);h=gcd(h1,h2);ans=0;//printf("%d %d\n",w,h);
for (i=1;i<=(h1*h2)/h;i++) for (j=1;j<=(w1*w2)/w;j++) 
if (a[(i-1)/(h2/h)+1][(j-1)/(w2/w)+1]==b[(i-1)/(h1/h)+1][(j-1)/(w1/w)+1]) ans++;
printf("%d\n",ans);
fclose(stdin);
fclose(stdout);
return 0;
}





















