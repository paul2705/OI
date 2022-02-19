#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	if (system("diff physics.out physics2.out")) cout<<0<<endl;
	else cout<<1<<endl;
	return 0;
}
