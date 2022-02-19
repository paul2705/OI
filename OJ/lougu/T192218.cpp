#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<string>
using namespace std;
char a[500],b[105];
int main(){
    int x1,x2,x3;
    char x,y,z;
    cin>>x1>>x2>>x3;
    cin>>b;
    for(int c=0;c<strlen(b);c++){
        if(b[c]=='-'){
            if(b[c-1]>b[c+1]) cout<<"-" ;
            else if(b[c-1]<'a'&&b[c+1]>='a') cout<<"-";
            else if(b[c-1]>='a'&&b[c+1]<'a') cout<<"-";
			else if(b[c-1]==b[c+1]) cout<<"-";
			else if(b[c-1]+1==b[c+1]&&b[c+1]!='a') continue;
			else if (b[c-1]=='-') cout<<"-";
			else if (b[c+1]=='-') cout<<"-";
			else if(c==0) cout<<"-";
			else if(c==strlen(b)-1) cout<<"-";
            else {
                x=b[c-1];y=b[c];z=b[c+1];
                if(x3==1){
                    for(int i=1;i<=z-x-1;i++) a[i]=x+i;
                }
                else if(x3==2){
                    for(int i=1;i<=z-x-1;i++) a[i]=z-i;
                }
                if(x1==2&&a[1]>='a'){
                    for(int i=1;i<=z-x-1;i++) a[i]-=32;
                }
				if (x1==3) for (int i=1;i<=z-x-1;i++) a[i]='*';
				for(int k=1;k<=z-x-1;k++){
                    for(int m=1;m<=x2;m++)cout<<a[k];
                }
            }
        }
        else cout<<b[c];
    }
    return 0;
}
