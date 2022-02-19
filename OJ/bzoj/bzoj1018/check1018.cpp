#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int cnt=0;
int main(){
	while (1){
		cnt++;
		system("./getinbzoj1018");
		system("./bzoj1018");
		system("./bzoj1018_bl");
		if (system("diff bzoj1018.out bzoj10181.out")) break;
		cout<<cnt<<endl;
	}
	return 0;
}
