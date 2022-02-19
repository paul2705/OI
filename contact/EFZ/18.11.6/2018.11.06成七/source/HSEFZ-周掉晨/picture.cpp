#include<bits/stdc++.h>
using namespace std;
long long h1,w1,h2,w2,h,w;
string s1,s2;
long long gcd(long long x,long long y)
{
	if (y==0) return x;
	else return gcd(y,x%y);
}
int main()
{
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
	cin>>h1>>w1;
	cin>>s1;
	cin>>h2>>w2;
	cin>>s2;
	long long n=s1.size(),m=s2.size();
	long long w=w1/gcd(w1,w2)*w2,h=h1/gcd(h1,h2)*h2;


	long long ans=0;
    for (int i=1;i<=h;i++)
        for (int j=1;j<=w;j++){
//        	cout<<i<<" "<<j<<" "<<endl;
        	int xx1,yy1,x2,y2;
        	if (i%(h/h1)==0) xx1=i/(h/h1);
        	else xx1=i/(h/h1)+1;
        	if (j%(w/w1)==0) yy1=j/(w/w1);
        	else yy1=j/(w/w1)+1;
        	


        	
         	if (i%(h/h2)==0) x2=i/(h/h2);
        	else x2=i/(h/h2)+1;
        	if (j%(w/w2)==0) y2=j/(w/w2);
        	else y2=j/(w/w2)+1;  
        	
        	int a=(xx1-1)*w1+yy1-1;
        	int b=(x2-1)*w2+y2-1;	
					

        	if (s1[a]==s2[b]) ans++;
        	
		}
		printf("%lld\n",ans);
//	for (int i=1;i<=h;i++){
//		for (int j=1;j<=w;j++) cout<<aa[i][j];
//		cout<<endl;
//	}
	fclose(stdin);fclose(stdout);
	return 0;
}
