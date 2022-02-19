#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,s[100005],ans;
int t0[1000005],t1[1000005];
void add(int a[],int x,int s)
{
	x++;
	while (x<=1000000){
	    a[x]+=s;
	    x+=x&-x;
	}
}
int sum(int a[],int x)
{
	x++;
	int ans=0; 
	while (x>0){
		ans+=a[x];
		x-=x&-x;
	}
	return ans;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&s[i]);
		s[i]=s[i-1]+s[i];
	}
	int ans=0;
	for (int k=0;k<=20;k++){
		
//		cout<<k<<endl;
		
		for (int i=1;i<=1000000;i++) t1[i]=t0[i]=0;
		int ans2=0;
		for (int i=0;i<=n;i++){
			
//			cout<<" "<<i<<endl;

            
			
		    int s0=sum(t0,s[i]%(1<<k)),ss0=sum(t0,1000000);
		    int s1=sum(t1,s[i]%(1<<k)),ss1=sum(t1,1000000);
		    
//		    cout<<s0<<" "<<ss0<<" "<<s1<<" "<<ss1<<endl;
		    
		    if (s[i]&(1<<k)){
		    	ans2=(ans2+s0+ss1-s1)%2;
		    	add(t1,s[i]%(1<<k),1);
		    }
		    else{
		    	ans2=(ans2+s1+ss0-s0)%2;
		    	add(t0,s[i]%(1<<k),1);
		    }
		}
		cout<<ans2<<endl;
		ans+=(1<<k)*ans2;
	}
	printf("%d\n",ans);
} 
