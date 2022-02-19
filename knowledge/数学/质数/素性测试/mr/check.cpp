#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
	system("./mr");
	system("./get_ans");
	if (system("diff test.out test.ans")) printf("No\n");
	else printf("Yes\n");
}

