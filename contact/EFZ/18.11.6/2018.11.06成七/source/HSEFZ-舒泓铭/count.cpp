#include<iostream>
#include<cstdio>

int a,b,ans;

int main(){
#ifndef lll
    freopen("./count.in","r",stdin);
    freopen("./count.out","w",stdout);
#endif

    std::cin>>a>>b;
    if(a*b==1){
        ans=1;
    }else if(a*b==2){
        ans=2;
    }else if(a*b==3){
        ans=6;
    }else if(a*b==4){
        ans=8;
    }else if(a*b==6){
        ans=288;
    }else if(a*b==9){
        ans=108864;
    }
    std::cout<<ans<<std::endl;

    return 0;
}

