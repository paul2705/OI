#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int cnt=0;
int main(){
	while (1){
		cnt++;
		system("time ./getin_seg");
		system("time ./two_seg");
		system("time ./two_seg_bl");
		if (system("diff seg.out seg1.out")) break;
		cout<<cnt<<endl;
	}
	return 0;
}
