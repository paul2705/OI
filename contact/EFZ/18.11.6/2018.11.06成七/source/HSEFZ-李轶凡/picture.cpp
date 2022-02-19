#include<bits/stdc++.h>
#define lint long long
#define MAXN 1000100
using namespace std;

int gcd(int a,int b){		//a>=b
	if(b==0) return a;
	return gcd(b,a%b);
}

int h1,w1,h2,w2,nh,nw;
char pic1[MAXN],pic2[MAXN];
int sh1,sw1,sh2,sw2;

lint ans=0;

lint query(lint a1,lint b1,char col){
//	cout<<"original:"<<a1<<" "<<b1<<endl;
	lint tans=0;
	a1=a1*sh1;
	b1=b1*sw1;
	lint a2=a1+sh1-1;
	lint b2=b1+sw1-1;
//	cout<<"now:"<<a1<<" "<<b1<<" "<<a2<<" "<<b2<<endl;
	lint pnta=a1/sh2;			//From x1/sh2*sh2 to (x1/sh2+1)*sh2-1
	lint pntb=b1/sw2;
	for( pnta=a1/sh2; pnta*sh2<=a2; pnta++)
			for( pntb=b1/sw2; pntb*sw2<=b2; pntb++){
//				cout<<"get:"<<pnta<<" "<<pntb<<endl;
				if(col!=pic2[pnta*w2+pntb]) continue;
//				cout<<"Still GET"<<endl;
				lint height=min((pnta+1)*sh2-1,a2)-max(pnta*sh2,a1)+1;
				lint wide=min((pntb+1)*sw2-1,b2)-max(pntb*sw2,b1)+1;
				tans+=height*wide;
			}
	return tans;

}

int main(){
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
	scanf("%d%d",&h1,&w1);
	scanf("%s",pic1);
	scanf("%d%d",&h2,&w2);
	scanf("%s",pic2);
	nh=h1*h2/gcd(max(h1,h2),min(h1,h2));
	sh1=nh/h1;
	sh2=nh/h2;
	nw=w1*w2/gcd(max(w1,w2),min(w1,w2));
	sw1=nw/w1;
	sw2=nw/w2;
//	cout<<nh<<" "<<nw<<" "<<sh1<<" "<<sh2<<" "<<sw1<<" "<<sw2<<endl;
	for(int i=0; i<h1; i++)
			for(int j=0; j<w1; j++){
				int loc=i*w1+j;		//the location of the char in h1
				ans+=query(i,j,pic1[loc]);
			}
	printf("%lld\n",ans);
	return 0;
}
