#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
char ch1[N],ch2[N];
int h1,w1,h2,w2;
typedef long long ll;
int Gh,Gr;
int rpl[N],lpl[N];
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int s[N];
int rps[N],lps[N];
inline ll solve(int id1,int id2){
	//cout<<id1<<"and"<<id2<<"que";
	int lp1=(id1-1)*w1+1,lp2=(id2-1)*w2+1;
	//cout<<lp1<<','<<lp2<<"::";
	ll p1=w2/Gr,p2=w1/Gr;
	ll l1=1,r1=p1;
	int plc1=1,plc2=0;
	ll ret=0;
	while(plc1<=w1){
		//cout<<l1<<"-->"<<r1<<"___";
		//
		if(rpl[plc1]>=lpl[plc1]){
			//cout<<rpl[plc1]<<' '<<lpl[plc1]<<"::>";
			ll r=(s[lp2+rpl[plc1]-1]-s[lp2+lpl[plc1]-1-1]);
			ll al=rpl[plc1]-lpl[plc1]+1;
			//cout<<r<<"|"<<al<<endl;
			ret+=1ll*p2*(ch1[lp1+plc1-1]=='1'?r:al-r);
		}
		if(plc2&&plc2<=w2&&rps[plc2]>=l1&&lps[plc2]<=l1){
			ll r2=rps[plc2],l2=lps[plc2];
			//cout<<l2<<"--"<<r2<<endl;
			int len=min(r1,r2)-max(l1,l2)+1;
			ret+=1ll*len*(ch1[lp1+plc1-1]==ch2[lp2+plc2-1]);
		}
		plc2=rpl[plc1]+1;
		if(lps[plc2]<=r1&&rps[plc2]>r1&&plc2<=w2&&plc2){
			ll r2=rps[plc2],l2=lps[plc2];
			int len=min(r1,r2)-max(l1,l2)+1;
			//cout<<l2<<'-'<<r2<<endl;
			ret+=1ll*len*(ch1[lp1+plc1-1]==ch2[lp2+plc2-1]);
		}
		plc1++;l1+=p1;r1+=p1;
	}
	//cout<<ret<<endl;
	return ret;
}
const int INF=0x3f3f3f3f;

inline void init(){
	ll p1=w2/Gr,p2=w1/Gr;
	ll l1=1,r1=p1,l2=1,r2=p2;
	//cout<<r1<<' '<<r2<<endl;
	int plc1=1,plc2=1; 
	while(plc1<=w1){
		lpl[plc1]=INF;
		while(r2<=r1&&plc2<=w2){
			if(l2>=l1)lpl[plc1]=min(lpl[plc1],plc2);
			rpl[plc1]=plc2;
			plc2++;l2+=p2;r2+=p2;
		}
		//cout<<lpl[plc1]<<','<<rpl[plc1]<<endl;
		plc1++;
		l1+=p1;r1+=p1;
	}
	l2=1,r2=p2;
	for(int i=1;i<=w2;i++){
		lps[i]=l2,rps[i]=r2;
		l2+=p2,r2+=p2;
	}
	return;
}

ll ans;
int main()
{
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
	scanf("%d%d",&h1,&w1);
	scanf("%s",ch1+1);
	scanf("%d%d",&h2,&w2);
	scanf("%s",ch2+1);
	if(w1>w2){
		swap(ch1,ch2);
		swap(h1,h2);
		swap(w1,w2);
	}
	for(int i=1;i<=h2*w2;++i){
		s[i]=s[i-1]+(ch2[i]=='1');
	}
	Gh=gcd(h1,h2);Gr=gcd(w1,w2);
	ll p2=h1/Gh,p1=h2/Gh;
	ll l1=1,r1=p1;
	int plc1=1,plc2=1;
	ll l2=1,r2=p2;
	init();
	while(plc1<=h1){
		//cout<<l1<<","<<r1<<endl;
		while(r2<=r1&&plc2<=h2){
			int len=min(r1,r2)-max(l1,l2)+1;
			//cout<<len<<"::";
			if(len>0)ans+=1ll*len*solve(plc1,plc2);
			plc2++;l2+=p2;r2+=p2;
		}
		if(l2<=r1&&plc2<=h2){
			int len=min(r1,r2)-max(l1,l2)+1;
			//cout<<len<<"::";
			if(len>0)ans+=1ll*len*solve(plc1,plc2);
		}
		plc1++;
		l1+=p1;r1+=p1;
	}
	printf("%lld\n",ans);
}
